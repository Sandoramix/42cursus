#!/usr/bin/zsh
source ~/.zshrc
make
valgrind --show-leak-kinds=all --leak-check=full ./pipex in cat "grep c" out
