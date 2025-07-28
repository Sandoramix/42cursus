import argparse
import os
import re
from typing import List, Tuple

TAB_SIZE = 4

C_CONTROL_KEYWORDS = {
    'if', 'for', 'while', 'switch', 'else', 'case', 'do', 'goto', 'return', 'sizeof'
}

def is_excluded(path: str, exclude_list: List[str]) -> bool:
    """Check if path contains any substring from exclude_list."""
    norm_path = os.path.normpath(path)
    for excl in exclude_list:
        norm_excl = os.path.normpath(excl)
        # If excluded is a directory prefix of path
        if os.path.commonpath([norm_path, norm_excl]) == norm_excl:
            return True
        # Or exact file match
        if norm_path == norm_excl:
            return True
    return False


def find_c_files(root: str, exclude: List[str]) -> List[str]:
    """Recursively find .c files under root, excluding specified paths."""
    c_files = []
    for dirpath, _, filenames in os.walk(root):
        if is_excluded(dirpath, exclude):
            continue
        for filename in filenames:
            full_path = os.path.join(dirpath, filename)
            if filename.endswith('.c') and not is_excluded(full_path, exclude):
                c_files.append(full_path)
    return c_files


def clean_content(content: str) -> str:
    """Strip comments and preprocessor directives, collapse newlines for parsing."""
    # Remove block comments (/* ... */)
    content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
    # Remove line comments (// ...)
    content = re.sub(r'//.*', '', content)
    # Remove preprocessor directives (#...)
    content = re.sub(r'^\s*#.*$', '', content, flags=re.MULTILINE)
    # Flatten multiline headers by replacing newline + spaces with a single space
    content = re.sub(r'\n\s*', ' ', content)
    return content


def extract_prototypes(content: str, include_static: bool) -> List[Tuple[str, str]]:
    """
    Extract function prototypes from C source content.

    Returns list of tuples: (function_name, full_prototype_str).
    """
    pattern = re.compile(
        r'''
        \s*                          # optional leading whitespace
        (static)?                      # optional 'static'
        \s*
        ([\w\s\*]+?)                      # return type (non-greedy)
        \s+([\*\w]+)                      # function name (can start with *)
        \s*\(([^)]*)\)                    # argument list (no nested parentheses)
        \s*\{                             # opening brace of function body
        ''',
        re.DOTALL | re.VERBOSE
    )

    prototypes = []
    for match in pattern.finditer(content):
        static_kw, ret_type, func_name, args = match.groups()

        # Skip control keywords (e.g., 'if', 'for')
        if func_name in C_CONTROL_KEYWORDS or func_name == 'main':
            continue
        # Skip static functions if not including them
        if static_kw and not include_static:
            continue

        ret_type_clean = re.sub(r'\s+', ' ', ret_type.strip())
        args_clean = re.sub(r'\s+', ' ', args.strip())
        full_proto = f"{static_kw + ' ' if static_kw else ''}{ret_type_clean} {func_name}({args_clean});"
        prototypes.append((func_name, full_proto))

    return prototypes

def tabs_to_reach_column(current_len, target_col):
    """
    Calculate how many tabs to add to move from current_len to at least target_col.
    Tabs advance to the next multiple of TAB_SIZE.
    """
    tabs_needed = 0
    pos = current_len
    while pos < target_col:
        tabs_needed += 1
        # advance pos to next tab stop
        pos = ((pos // TAB_SIZE) + 1) * TAB_SIZE
    return tabs_needed

def tab_align(text, target_length):
    """
    Pad 'text' with tabs only so total length reaches or surpasses target_length,
    assuming tab stops every TAB_SIZE characters.
    """
    current_len = len(text)
    tabs_needed = tabs_to_reach_column(current_len, target_length)
    return text + ("\t" * tabs_needed)

def parse_and_format_prototypes(prototypes: List[Tuple[str, str]], no_indent: bool) -> list[str]:
    """
    Format prototypes for output.
    Align by return type unless no_indent is True.
    """
    # Deduplicate by function name (keep last occurrence)
    unique_protos = {name: proto for name, proto in prototypes}

    if no_indent:
        return [unique_protos[name] for name in sorted(unique_protos)]

    entries = []
    for name in sorted(unique_protos, key=lambda n: n.lstrip('*')):
        proto = unique_protos[name]
        # Regex to extract parts from prototype string for alignment
        match = re.match(
            r'\s?(static\s+)?(.+?)(\**)?\s*(\w+)\s*\((.*)\);\s?',
            proto.strip()
        )
        if not match:
            # If no match, fallback to printing as-is with empty name/args
            entries.append((proto, "", ""))
            continue

        static_kw, ret_type, stars, fname, args = match.groups()
        full_ret = ((static_kw or '') + ret_type).strip()
        full_name = f"{stars or ''}{fname}"
        entries.append((full_ret, full_name, args.strip()))

    # Filter out entries missing function name

    filtered = [e for e in entries if e[1]]


    if not filtered:
        return [e[0] for e in entries]

    max_len = max(len(ret_type) for ret_type, _, _ in filtered)
    max_tab_col = ((max_len // TAB_SIZE) + 1) * TAB_SIZE
    lines = [
        f"{tab_align(ret, max_tab_col)}{name}({args});"
        for ret, name, args in filtered
    ]
    return lines

def group_aligned_prototypes(
    aligned_prototypes: List[str],
    all_protos: List[Tuple[str, str]],
    file_map: dict,
    group_level: int,
    root_path: str
) -> str:
    """
    Group already aligned prototypes by file path level and return the formatted string.
    """
    grouped = {}

    for (name, _), aligned_proto in zip(all_protos, aligned_prototypes):
        source_file = file_map.get(name)
        if not source_file:
            continue
        rel_path = os.path.relpath(source_file, root_path)
        parts = rel_path.split(os.sep)
        if group_level == 0:
            group_key = rel_path
        else:
            group_key = os.sep.join(parts[:max(1, len(parts) - group_level)])
        grouped.setdefault(group_key, []).append(aligned_proto)

    output_sections = []
    for group in sorted(grouped):
        section = f"// {group}\n" + "\n".join(grouped[group])
        output_sections.append(section)
    return "\n\n".join(output_sections)

def main():
    parser = argparse.ArgumentParser(description="Extract C function prototypes.")
    parser.add_argument("path", nargs="?", default=".", help="Root directory to scan for .c files.")
    parser.add_argument("-e", "--exclude", action="append", default=[], help="Files or directories to exclude. Can be specified multiple times.")
    parser.add_argument("-s", "--include-static", default=False, action="store_true", help="Include static functions.")
    parser.add_argument("-o", "--save", metavar="FILE", help="File to save the output.")
    parser.add_argument("-n", "--no-indent", action="store_true", help="Disable indentation of function names.")
    parser.add_argument("-g", "--group", nargs="?", const=0, type=int, help="Group functions by file or directory level. 0 (Default) means by file, higher values are more generic directory grouping.")
    args = parser.parse_args()

    all_prototypes = []
    # map function name -> source file
    file_map = {}
    c_files = find_c_files(args.path, args.exclude)

    for c_file in c_files:
        with open(c_file, 'r', encoding='utf-8', errors='ignore') as f:
            content = clean_content(f.read())
            #rel_path = os.path.relpath(c_file, args.path)
            prototypes = extract_prototypes(content, args.include_static)

            for name, proto in prototypes:
                file_map[name] = c_file
                all_prototypes.append((name, proto))

    aligned = parse_and_format_prototypes(all_prototypes, args.no_indent)

    if args.group is not None:
        output = group_aligned_prototypes(
            aligned_prototypes=aligned,
            all_protos=all_prototypes,
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
