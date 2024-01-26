NAME=push_swap

NAME_UPPER = $(shell echo -n ${NAME} | tr 'a-z' 'A-Z')

ROOTDIR=./src

LIBFTX_DIR=$(ROOTDIR)/libftx

# --------------
SRC = main.c \
	./src/ps_push.c \
	./src/ps_rotate.c \
	./src/ps_swap.c \
	./src/ps_utils.c

OBJ = $(SRC:.c=.o)

# ----RULES-----

CC=cc
CEXTRAFLAGS=
CFLAGS=-Wall -Wextra -Werror $(CEXTRAFLAGS)
COMPILE=$(CC) $(CFLAGS)
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
debug:
	$(MAKE) CEXTRAFLAGS=-g

re: fclean all
debug-re: fclean debug

ARG=1 2 3 4
main: all
	./$(NAME) $(ARG)
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