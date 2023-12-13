NAME=so_long

CC=cc
CFLAGS=-Wall -Werror -Wextra
COMPILE=$(CC) $(CFLAGS)
RM=rm -rf

ROOTDIR=./src

LIBFTX_DIR=$(ROOTDIR)/libftx
MLX_DIR=$(ROOTDIR)/minilibx

INCLUDES=-I$(ROOTDIR)/includes -I$(LIBFTX_DIR)/includes -I$(MLX_DIR)

VALGRIND=@valgrind --leak-check=full -s --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes


SRC= ./src/map_parsing/parsemap.c \
	./src/utils.c \
	./src/main.c \
	./src/map_parsing/inputctrl.c

OBJ=$(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTX_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(COMPILE) $(INCLUDES) $(OBJ) -L$(LIBFTX_DIR) -lft -L$(MLX_DIR) -lmlx_$(shell uname) -lXext -lX11 -o $(NAME)
	@echo "$(GREEN)[SO_LONG]:\tPROGRAM CREATED SUCCESSFULLY$(R)"

clean:
	@$(RM) $(OBJ)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFTX_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFTX_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(BLUE)[SO_LONG]:\tPROGRAM DELETED$(R)"

re: fclean all

%.o: %.c
	@$(COMPILE) $(INCLUDES) -c $< -o $@

valgrind: all
	@$(VALGRIND) ./$(NAME) valid0.ber
download:
	@wget https://cdn.intra.42.fr/document/document/21656/minilibx-linux.tgz
	@tar -xf minilibx-linux.tgz
	@mv minilibx-linux $(ROOTDIR)/minilibx
	@$(RM) minilibx-linux.tgz

# ---COLORS---
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
R=\033[0m
# ------------

.PHONY: all clean fclean re
.SILENT: