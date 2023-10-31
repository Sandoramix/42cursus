NAME=libftprintf.a

RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra #-Werror
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

SRC = ft_printf.c \
	ft_pfflag.c \
	ft_pfbonushandler.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(COMPILE) $< -o $@ -Ilibft -I.

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@cp libft/libft.a $(NAME)
	@$(ARCHIVE) $(OBJ)

bonus: all

clean:
	@$(MAKE) -C libft fclean
	@$(RM) $(OBJ)
	@echo "Removed Printf objects!"

fclean: clean
	@$(RM) $(NAME)
	@echo Removed $(NAME)!

re: fclean all

# TODO REMOVE ME


build: main.c
	@$(MAKE)
	@$(CC) main.c -w -Ilibft -L. -lftprintf
	@clear
m: build
	@./a.out
b: build
	@./a.out b

.PHONY: all clean fclean re bonus
