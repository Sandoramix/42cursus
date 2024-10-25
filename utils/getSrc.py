#!/usr/bin/env python3
import argparse as agp
import os
import glob

VERSION = "Current %(prog)s's version: v1"


argParser = agp.ArgumentParser(description="Tool which creates locates and writes every src & bonus files for your project")
argParser.add_argument("--path", '-p', default='.',  help="Path to look for")
argParser.add_argument("--exclude", '-e', default=None,  help="Paths to exclude from lookup, each separated by comma")
argParser.add_argument("--version", "-v", help="Show the program's version", action='version', version=VERSION)
argParser.add_argument("--output","-o",  nargs='?', default='makefile.srcs', help="Output file. Default: 'makefile.srcs'")
argParser.add_argument("--extension", '-ext', nargs='?', default='c', help="Extension to look for. Default: 'c'")

args = argParser.parse_args()

if 'version' in args:
	exit(0)

PATH = args.path
EXCLUDE_DIRS = args.exclude.split(",") if ('exclude' in args and args.exclude is not None) else []
OUTFILE = args.output if 'output' in args else 'makefile.srcs'

srcs = []
bonuses = []

def updateExcludedPaths():
	"""
	Find excluded path (every subfolder folder that is a part of another repository, or is in `EXCLUDE_DIRS`)
	"""
	to_exclude = set(EXCLUDE_DIRS)
	for x in os.walk(PATH):
		if x[0].startswith("./.git"): continue
		if (".git" in x[0]):
			split = x[0].split(".git")[0]
			if (split.endswith("/")):
				split = split[:len(split) - 1]
			to_exclude.add(split)
			continue
	return (list(to_exclude))



to_exclude = updateExcludedPaths()
is_excluded = lambda x: len([i for i in to_exclude if i in x]) > 0

EXT_FILTER = args.extension if 'extension' in args else 'c'

for x in os.walk(PATH):
	for y in glob.glob(os.path.join(x[0], f'*.{EXT_FILTER}')):
		if is_excluded(y): continue
		if (y.endswith(f"_bonus.{EXT_FILTER}")): bonuses.append(y)
		elif y.endswith(f".{EXT_FILTER}"): srcs.append(y)

with open(OUTFILE, "w") as file:
	out = "SRC = "
	for i, v in enumerate(sorted(srcs)):
		out += ("" if i == 0 else "\t") + v + (" \\" if i < len(srcs) - 1 else "") + "\n"
	if len(bonuses) > 0:
		out += "\nSRC_BONUS = "
		for i, v in enumerate(sorted(bonuses)):
			out += ("" if i == 0 else "\t") + v + (" \\" if i < len(bonuses) - 1 else "") + "\n"
	file.write(out)
	print(out)
