NAME = pipex
PNAME = $(shell echo -n ${NAME} | tr 'a-z' 'A-Z')

ROOTDIR = ./src
LIBFTX_DIR = $(ROOTDIR)/libftx


# ----RULES-----
CC = cc
INCLUDES = -I$(ROOTDIR)/includes -I$(LIBFTX_DIR)/includes
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) $(EXTRAFLAGS)
RM = rm -rf


# --------------

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTX_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFTX_DIR) -lft
	@echo "$(GREEN)[$(PNAME)]:\tPROGRAM CREATED$(R)"

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFTX_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFTX_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(BLUE)[$(PNAME)]:\tPROGRAM DELETED$(R)"

re: fclean all

# ----UTILS-----
debug:
	$(MAKE) EXTRAFLAGS=-g

debug-re: fclean debug
ARG=""
valgrind: all
	@$(VALGRIND) ./$(NAME) $(ARG)
valgrindre: re valgrind


# ----COLORS----
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
R=\033[0m
# --------------

VALGRIND=@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

# ----OTHER-----
.PHONY: all clean fclean re valgrind
.SILENT: