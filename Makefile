NAME=so_long

CC=cc
CFLAGS=-Wall -Werror -Wextra
COMPILE=$(CC) $(CFLAGS)
RM=rm -rf

SRC=utils.c

OBJ=$(SRC:.c=.o)

FT_DIR=./libftx
INCLUDE=$(FT_DIR)/includes

all: $(NAME)

%.o: %.c
	@$(COMPILE) -c $< -o $@ -I. -I$(INCLUDE)

$(NAME): $(OBJ)
	$(MAKE) -C $(FT_DIR)
	$(COMPILE)  main.c  -L$(FT_DIR) -lft -I$(INCLUDE) -I. -o $(NAME)

clean:
	$(MAKE) -C $(FT_DIR) clean
	@$(RM) *.o
fclean: clean
	$(MAKE) -C $(FT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: re all $(NAME) clean fclean
