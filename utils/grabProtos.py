import argparse
import os
import re
from typing import List, Tuple

TAB_SIZE = 4

C_CONTROL_KEYWORDS = {
    'if', 'for', 'while', 'switch', 'else', 'case', 'do', 'goto', 'return', 'sizeof'
}

# -------------------------- File Discovery --------------------------

def is_excluded(path: str, exclude_list: List[str]) -> bool:
    norm_path = os.path.normpath(path)
    for excl in exclude_list:
        norm_excl = os.path.normpath(excl)
        if os.path.commonpath([norm_path, norm_excl]) == norm_excl:
            return True
        if norm_path == norm_excl:
            return True
    return False

def find_c_files(root: str, exclude: List[str]) -> List[str]:
    c_files = []
    for dirpath, _, filenames in os.walk(root):
        if is_excluded(dirpath, exclude):
            continue
        for filename in filenames:
            full_path = os.path.join(dirpath, filename)
            if filename.endswith('.c') and not is_excluded(full_path, exclude):
                c_files.append(full_path)
    return c_files

# -------------------------- Content Cleaning --------------------------

def clean_content(content: str) -> str:
    content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
    content = re.sub(r'//.*', '', content)
    content = re.sub(r'^\s*#.*$', '', content, flags=re.MULTILINE)
    content = re.sub(r'\n\s*', ' ', content)
    return content

# -------------------------- Prototype Extraction --------------------------

def extract_prototypes(content: str, include_static: bool) -> List[Tuple[str, str]]:
    pattern = re.compile(
        r'''
        \s*                          # optional leading whitespace
        (static)?                     # optional 'static'
        \s*
        ([\w\s\*]+?)                  # return type (non-greedy)
        \s+([\*\w]+)                  # function name (can start with *)
        \s*\(([^)]*)\)                # argument list
        \s*\{                         # opening brace of function body
        ''',
        re.DOTALL | re.VERBOSE
    )

    prototypes = []
    for match in pattern.finditer(content):
        static_kw, ret_type, func_name, args = match.groups()
        if func_name in C_CONTROL_KEYWORDS or func_name == 'main':
            continue
        if static_kw and not include_static:
            continue

        ret_type_clean = re.sub(r'\s+', ' ', ret_type.strip())
        args_clean = re.sub(r'\s+', ' ', args.strip())
        full_proto = f"{static_kw + ' ' if static_kw else ''}{ret_type_clean} {func_name}({args_clean});"
        prototypes.append((func_name, full_proto))

    return prototypes

# -------------------------- Tab Handling --------------------------

def tabs_to_reach_column(current_len, target_col):
    tabs_needed = 0
    pos = current_len
    while pos < target_col:
        tabs_needed += 1
        pos = ((pos // TAB_SIZE) + 1) * TAB_SIZE
    return tabs_needed

def tab_align(text, target_length):
    current_len = len(text)
    tabs_needed = tabs_to_reach_column(current_len, target_length)
    return text + ("\t" * tabs_needed)

# -------------------------- Prototype Formatting --------------------------

def parse_and_format_prototypes(
    prototypes: List[Tuple[str, str]],
    no_indent: bool
) -> list[str]:
    unique_protos = {name: proto for name, proto in prototypes}
    entries = []

    for name in sorted(unique_protos, key=lambda n: n.lstrip('*')):
        proto = unique_protos[name]
        match = re.match(
            r'\s?(static\s+)?(.+?)(\**)?\s*(\w+)\s*\((.*)\);\s?',
            proto.strip()
        )
        if not match:
            entries.append((proto, "", ""))
            continue

        static_kw, ret_type, stars, fname, args = match.groups()
        full_ret = ((static_kw or '') + ret_type).strip()
        full_name = f"{stars or ''}{fname}"
        entries.append((full_ret, full_name, args.strip()))

    filtered = [e for e in entries if e[1]]
    if not filtered:
        return [e[0] for e in entries]

    # Alignment calculation
    max_len = max(len(ret_type) for ret_type, _, _ in filtered)
    max_tab_col = ((max_len // TAB_SIZE) + 1) * TAB_SIZE

    lines = []

    for ret, name, args in filtered:
        first_line = f"{tab_align(ret, max_tab_col)}{name}("
        lines.append(f"{first_line}{args});")

    return lines

# -------------------------- Grouping --------------------------

def group_aligned_prototypes(
    aligned_prototypes: List[str],
    file_map: dict,
    group_level: int,
    root_path: str
) -> str:
    """
    Group aligned prototypes by file path level.
    Always show full path relative to root_path, even if grouping by last folder.
    """
    grouped = {}
    root_abs = os.path.abspath(root_path)

    for proto in aligned_prototypes:
        match = re.search(r'(\**\w+)\s*\(', proto)
        if not match:
            continue

        func_name = match.group(1).lstrip('*')
        source_file = file_map.get(func_name)
        if not source_file:
            continue

        # Full relative path from root_path
        rel_path_from_root = os.path.relpath(source_file, root_abs)
        dir_parts = os.path.dirname(rel_path_from_root).split(os.sep)

        if group_level == 0:
            # Group by file
            group_key = os.path.join(".", rel_path_from_root)
        else:
            # Group by last N folders, but show full relative path
            take = min(len(dir_parts), group_level)
            # Last N folders for grouping
            last_n_parts = dir_parts[-take:] if take > 0 else []
            # Full relative path to this file's folder
            group_key = os.path.join(".", *dir_parts)

        grouped.setdefault(group_key, []).append(proto)

    output_sections = []
    for group in sorted(grouped):
        section = f"// {group}\n" + "\n".join(grouped[group])
        output_sections.append(section)

    return "\n\n".join(output_sections)

# -------------------------- Main --------------------------

def main():
    parser = argparse.ArgumentParser(description="Extract C function prototypes.")
    parser.add_argument("path", nargs="?", default=".", help="Root directory to scan for .c files.")
    parser.add_argument("-e", "--exclude", action="append", default=[], help="Files or directories to exclude. Can be specified multiple times.")
    parser.add_argument("-s", "--include-static", default=False, action="store_true", help="Include static functions.")
    parser.add_argument("-o", "--save", metavar="FILE", help="File to save the output.")
    parser.add_argument("-n", "--no-indent", action="store_true", help="Disable indentation of function names.")
    parser.add_argument("-g", "--group", nargs="?", const=0, type=int, help="Group functions by file or directory level.")
    args = parser.parse_args()

    all_prototypes = []
    file_map = {}
    c_files = find_c_files(args.path, args.exclude)

    for c_file in c_files:
        with open(c_file, 'r', encoding='utf-8', errors='ignore') as f:
            content = clean_content(f.read())
            prototypes = extract_prototypes(content, args.include_static)
            for name, proto in prototypes:
                file_map[name] = c_file
                all_prototypes.append((name, proto))

    aligned = parse_and_format_prototypes(all_prototypes, args.no_indent,)

    if args.group is not None:
        output = group_aligned_prototypes(
            aligned_prototypes=aligned,
            file_map=file_map,
            group_level=args.group,
            root_path=args.path
        )
    else:
        output = "\n".join(aligned)

    if args.save:
        with open(args.save, 'w', encoding='utf-8') as f:
            f.write(output)
    print(output)

if __name__ == "__main__":
    main()
