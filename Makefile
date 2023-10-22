NAME=libftprintf.a

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(COMPILE) $< -o $@ -Ilibft

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(ARCHIVE) $(OBJ)

clean:
	@$(MAKE) -C libft fclean
	@$(RM) *.o
	@echo "Removed Printf objects!"

fclean: clean
	@$(RM) $(NAME)
	@echo Removed $(NAME)!

re: fclean all

# TODO REMOVE ME

main: re
	@$(CC) $(CFLAGS) main.c -Llibft -lft -Ilibft -L. -lftprintf libft/libft.a

.PHONY: all clean fclean re bonus