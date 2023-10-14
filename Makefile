NAME = libft.a
HNAME = libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rcs $(NAME)

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
	./ft_calloc.c

SRC_BONUS = ./ft_lstnew_bonus.c \
	./ft_lstadd_front_bonus.c \
	./ft_lstadd_back_bonus.c \
	./ft_lstclear_bonus.c \
	./ft_lstdelone_bonus.c \
	./ft_lstlast_bonus.c \
	./ft_lstmap_bonus.c \
	./ft_lstsize_bonus.c \
	./ft_lstiter_bonus.c


OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

%.o: %.c
	$(COMPILE) $< -o $@

$(NAME): $(OBJ)
	$(ARCHIVE) $(OBJ)

bonus: $(NAME) $(OBJ_BONUS)
	$(ARCHIVE) $(OBJ_BONUS)

RM = rm -f
clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
