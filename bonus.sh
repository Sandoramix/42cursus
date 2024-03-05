#!/usr/bin/zsh
source ~/.zshrc
make debug-bonus
valgrind --show-leak-kinds=all --leak-check=full ./pipex_bonus heredoc EOF cat echo out
#--log-file=leak.log