#!/usr/bin/env python3
import argparse as agp
import os
import glob

VERSION = "Current %(prog)s's version: v1"


argParser = agp.ArgumentParser(description="Tool which creates locates and writes every src & bonus files for your project")
argParser.add_argument("--path", '-p', default='.',  help="Path to look for")
argParser.add_argument("--version", "-v", help="Show the program's version", action='version', version=VERSION)
argParser.add_argument("--output","-o",  nargs='?', default='makefile.srcs', help="Output file")


args = argParser.parse_args()

if 'version' in args:
	exit(0)

PATH = args.path
OUTFILE = args.output if 'output' in args else 'makefile.srcs'

srcs = []
bonuses = []

for x in os.walk(PATH):
	if (x == '.git'): continue
	for y in glob.glob(os.path.join(x[0], '*.c')):
		if (y.endswith("_bonus.c")): bonuses.append(y)
		elif y.endswith(".c"): srcs.append(y)

with open(OUTFILE, "w") as file:
	out = "SRC = "
	for i, v in enumerate(srcs):
		out += ("" if i == 0 else "\t") + v + (" \\" if i < len(srcs) - 1 else "") + "\n"
	out += "\nSRC_BONUS = "
	for i, v in enumerate(bonuses):
		out += ("" if i == 0 else "\t") + v + (" \\" if i < len(bonuses) - 1 else "") + "\n"
	file.write(out)
	print(out)
