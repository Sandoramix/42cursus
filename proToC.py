#!/usr/bin/env python3
import argparse as agp
import os

VERSION = "Current %(prog)s's version: v1"

ARGS = {
	"FILE":"file",
	"VERSION":"version"
}
IGNORED_STARTS = ('/', '#', ' ', '\n', 'typedef', 'struct', '*')
def get_header():
	# TODO IMPLEMENT THE 42 HEADER
	return ""
def get_include(header):
	return f'#include "{header if ".h" in header else f"{header}.h"}"\n'

argParser = agp.ArgumentParser(description="Tool which creates .c files based of prototypes found inside a specified file")
argParser.add_argument(ARGS['FILE'],type=str, help="File with prototypes.\te.g.: 'libft.h'")
argParser.add_argument("--version", "-v", help="Show the program's version", action=ARGS['VERSION'], version=VERSION)


args = argParser.parse_args()

if ARGS['VERSION'] in args:
	exit(0)

FILENAME = args.file

if not os.path.exists(FILENAME):
	print(f"file {FILENAME} not found.")
	exit(1)

with open(FILENAME, "r") as outfile:
	F_LINES = outfile.read().splitlines()

isSkipping = False
for idx, line in enumerate(F_LINES):

	if line == '' or line.startswith(IGNORED_STARTS): continue
	line = line.strip()
	if line.startswith('{'): isSkipping = True
	if line.startswith('}'):
		isSkipping = False
		continue
	if isSkipping: continue

	try:
		prototype = line[:len(line) - 1]


		while prototype.find("\t\t") != -1:
			prototype = prototype.replace("\t\t","\t")
		prototype = prototype.replace("\t",' ')

		outfile = prototype.replace("*", "")
		outfile = outfile.split(' ')[1].split('(')[0]
		outfile = f'{outfile}.c'

		function = f'{prototype}\n{{\n}}'
		function = function[:function.find(' ')] + '\t' + function[function.find(' ')+1:]

		out_content = f'{get_header()}{get_include(FILENAME)}\n{function}'
		with open(outfile, 'w') as cfile:
			cfile.write(out_content)
			print(f'created\t{outfile}')
	except Exception as e:
		print(f"Error in {FILENAME}:{idx+1}:\tCould not generate the file.\n\tReason:\t{e}")