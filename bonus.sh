#!/usr/bin/zsh
source ~/.zshrc
make debug-bonus
valgrind --show-leak-kinds=all --leak-check=full ./pipex_bonus heredoc EOF "ls -l" "awk '{print \$1}'" out

#--log-file=leak.log