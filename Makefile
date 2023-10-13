NAME = libft.a
HNAME = libft.h
CC = cc
#CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)
RANLIB = ranlib $(NAME)

SRC = $(shell find . -name "ft_*.c" ! -name "ft_*_bonus.c")
SRC_BONUS = $(shell find . -name "*_bonus.c")

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJ) $(HNAME)
	@$(COMPILE) $(SRC)
	@$(ARCHIVE) $(OBJ)
	@$(RANLIB)

bonus: $(OBJ_BONUS) $(HNAME)
	@$(COMPILE) $(SRC_BONUS)
	@$(ARCHIVE) $(OBJ_BONUS)
	@$(RANLIB)


RM = rm -f
clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
