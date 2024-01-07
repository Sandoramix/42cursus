NAME=push_swap

NAME_UPPER = $(shell echo -n ${NAME} | tr 'a-z' 'A-Z')

ROOTDIR=./src

LIBFTX_DIR=$(ROOTDIR)/libftx
<<<<<<< HEAD

# --------------
SRC= ./main.c
=======
MLX_DIR=$(ROOTDIR)/minilibx

# --------------
SRC= main.c
>>>>>>> b7a48ab5163fd46e454e662275b7afa807113c0b

OBJ=$(SRC:.c=.o)

# ----RULES-----

CC=cc
CFLAGS=-Wall -Wextra -Werror
COMPILE=$(CC) $(CFLAGS) -g
RM=rm -rf

INCLUDES=-I$(ROOTDIR)/includes -I$(LIBFTX_DIR)/includes
LIB_INCLUDES=-L$(LIBFTX_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTX_DIR)
	$(COMPILE) $(INCLUDES) $(OBJ) -o $(NAME) $(LIB_INCLUDES) -lft
	@echo "$(GREEN)[$(NAME_UPPER)]:\tPROGRAM CREATED SUCCESSFULLY$(R)"

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFTX_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFTX_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(BLUE)[$(NAME_UPPER)]:\tPROGRAM DELETED$(R)"

# --------------

re: fclean all
main: all
	@./$(NAME) $(ARG)
# --------------

%.o: %.c
	@$(COMPILE) $(INCLUDES) -c $< -o $@

# ----UTILS-----
VALGRIND=@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes
valgrind: all
	@$(VALGRIND) ./$(NAME) $(ARG)
valgrindre: re valgrind

# ----OTHER-----
.PHONY: all clean fclean re valgrind
.SILENT:

# ----COLORS----
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
R=\033[0m
# --------------