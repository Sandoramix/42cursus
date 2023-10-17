NAME=libftprintf.a

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

all: $(NAME)

%.o: %.c
	@$(COMPILE) $< -o $@


$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(ARCHIVE) $(OBJ)

clean:
	@$(MAKE) -C libft fclean
	@$(RM) *.o
	@echo "Removed printf objects!"

fclean: clean
	@$(RM) $(NAME)
	@echo Removed $(NAME)!

re: fclean all

.PHONY: all clean fclean re bonus