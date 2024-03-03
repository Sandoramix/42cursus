#!/usr/bin/zsh
source ~/.zshrc
make debug-bonus
valgrind --trace-children=yes --show-leak-kinds=all --leak-check=full ./pipex_bonus heredoc EOF cat cat noexists out
