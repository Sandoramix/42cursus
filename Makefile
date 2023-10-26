NAME=libftprintf.a

RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)

SRC = ft_printf.c \
	./libft_extra/ft_getaddr.c \
	./libft_extra/ft_iabs.c \
	./libft_extra/ft_ipow.c \
	./libft_extra/ft_istrlen.c \
	./libft_extra/ft_itoa_base.c \
	./libft_extra/ft_itohex.c \
	./libft_extra/ft_memrev.c \
	./libft_extra/ft_mtxfree.c \
	./libft_extra/ft_nbr_len.c \
	./libft_extra/ft_strcount_c.c \
	./libft_extra/ft_stridxofchar.c \
	./libft_extra/ft_stridxofstr.c \
	./libft_extra/ft_strpadend.c \
	./libft_extra/ft_strpadstart.c \
	./libft_extra/ft_strpushchar.c \
	./libft_extra/ft_strreplace.c \
	./libft_extra/ft_strreplace_first.c \
	./libft_extra/ft_strtoupper.c \
	./libft_extra/ft_uitoa.c \
	./libft_extra/ft_ultoa_base.c \
	./libft_extra/ft_ulnbr_len.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(COMPILE) $< -o $@ -Ilibft -I.

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@cp libft/libft.a $(NAME)
	@$(ARCHIVE) $(OBJ)

clean:
	@$(MAKE) -C libft fclean
	@$(RM) $(OBJ)
	@echo "Removed Printf objects!"

fclean: clean
	@$(RM) $(NAME)
	@echo Removed $(NAME)!

re: fclean all

# TODO REMOVE ME

main: main.c
	@$(MAKE)
	@$(CC) main.c -Ilibft -L. -lftprintf
	@clear
	@./a.out

.PHONY: all clean fclean re bonus
