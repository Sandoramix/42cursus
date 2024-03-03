#!/usr/bin/zsh
source ~/.zshrc
make debug-bonus
valgrind --trace-children=yes --show-leak-kind=all ./pipex_bonus heredoc EOF cat cat out