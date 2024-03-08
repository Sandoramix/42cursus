#!/usr/bin/zsh
source ~/.zshrc
make
valgrind --show-leak-kinds=all --leak-check=full ./pipex in "ls -l" "grep '4096 c' " out
