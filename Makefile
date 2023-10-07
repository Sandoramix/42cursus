NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
ARCHIVE = ar rc $(NAME)
RANLIB = ranlib $(NAME)

SRC = $(shell find . -name "*.c" ! -name "*_bonus.c")
SRC_BONUS = $(shell find . -name "*_bonus.c")

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

$(NAME):
	@$(COMPILE) $(SRC)
	@$(ARCHIVE) $(OBJ)
	@$(RANLIB)

bonus:
	@$(COMPILE) $(SRC_BONUS)
	@$(ARCHIVE) $(OBJ_BONUS)
	@$(RANLIB)


RM = rm -f
clean:
	@$(RM) $(OBJ)
fclean:
	@$(RM) $(NAME)
cls: fclean clean


re: fclean all

so:
	$(CC) -fPIC -c $(SRC)
	$(CC) -shared -Wl,-soname,libft.so -o libft.so *.o

.PHONY: all clean fclean aclean re
