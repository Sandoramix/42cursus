NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)
RM = rm -f

SRC = ./ft_toupper.c \
	./ft_tolower.c \
	./ft_split.c \
	./ft_memcpy.c \
	./ft_strnstr.c \
	./ft_isalnum.c \
	./ft_strlcat.c \
	./ft_strchr.c \
	./ft_isdigit.c \
	./ft_itoa.c \
	./ft_strlcpy.c \
	./ft_strrchr.c \
	./ft_isprint.c \
	./ft_isascii.c \
	./ft_strjoin.c \
	./ft_striteri.c \
	./ft_strncmp.c \
	./ft_putchar_fd.c \
	./ft_memset.c \
	./ft_strlen.c \
	./ft_atoi.c \
	./ft_strmapi.c \
	./ft_bzero.c \
	./ft_substr.c \
	./ft_putstr_fd.c \
	./ft_strdup.c \
	./ft_isalpha.c \
	./ft_memchr.c \
	./ft_memmove.c \
	./ft_putendl_fd.c \
	./ft_putnbr_fd.c \
	./ft_strtrim.c \
	./ft_memcmp.c \
	./ft_calloc.c \
	./ft_lstnew_bonus.c \
	./ft_lstadd_front_bonus.c \
	./ft_lstadd_back_bonus.c \
	./ft_lstclear_bonus.c \
	./ft_lstdelone_bonus.c \
	./ft_lstlast_bonus.c \
	./ft_lstmap_bonus.c \
	./ft_lstsize_bonus.c \
	./ft_lstiter_bonus.c \
	./extra/ft_strpadstart.c \
	./extra/ft_strpadend.c \
	./extra/ft_itohex.c \
	./extra/ft_istrlen.c \
	./extra/ft_nbr_len.c \
	./extra/ft_memrev.c \
	./extra/ft_strtoupper.c \
	./extra/ft_getaddr.c \
	./extra/ft_itoa_base.c \
	./extra/ft_ipow.c \
	./extra/ft_stridxofchar.c \
	./extra/ft_stridxofstr.c \
	./extra/ft_iabs.c \
	./extra/ft_uitoa.c \
	./extra/ft_uitoa_base.c \
	./extra/ft_mtxfree.c \
	./extra/ft_strreplace_first.c \
	./extra/ft_strreplace.c \
	./extra/ft_strcount_c.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	@$(COMPILE) $< -o $@ -I.

$(NAME): $(OBJ)
	@$(ARCHIVE) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@echo Removed Libft objects!

fclean: clean
	@$(RM) $(NAME)
	@echo Removed $(NAME)!

re: fclean all

.PHONY: all clean fclean re
