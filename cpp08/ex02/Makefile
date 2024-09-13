NAME=...

CPPFLAGS=-g -Wall -Wextra -Werror -std=c++98 -I.
CC = c++

SRCS = main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)
	@echo "\e[0;93m[$(NAME)] compiled!\e[0m"

clean:
fclean: clean
	@rm -f $(NAME)
	@echo "\e[0;91m[$(NAME)] deleted!\e[0m"

re: fclean all

val: all
	clear
	valgrind --quiet ./$(NAME)

.PHONY: all clean fclean re
.SILENT: