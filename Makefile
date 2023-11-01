NAME=libftprintf.a

RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra #-Werror
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

SRC = ./ft_pfbonushandler.c \
	./ft_pfflag.c \
	./ft_printf.c \
	./utils/ft_getaddr.c \
	./utils/ft_iabs.c \
	./utils/ft_istrlen.c \
	./utils/ft_itohex.c \
	./utils/ft_nbr_len.c \
	./utils/ft_stridxofstr.c \
	./utils/ft_strpad.c \
	./utils/ft_strtoupper.c \
	./utils/ft_uitoa.c \
	./utils/ft_ulnbr_len.c \
	./utils/ft_ultoa_base.c

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
