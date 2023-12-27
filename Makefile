NAME=so_long

ROOTDIR=./src

LIBFTX_DIR=$(ROOTDIR)/libftx
MLX_DIR=$(ROOTDIR)/minilibx

# --------------
SRC= main.c \
	./src/sl_events.c \
	./src/sl_parse_map.c \
	./src/sl_textures.c \
	./src/sl_enemies.c \
	./src/sl_utils.c \
	./src/sl_time.c \
	./src/sl_bounds.c

OBJ=$(SRC:.c=.o)

# ----RULES-----

CC=cc
CFLAGS=-Wall -Wextra -Werror
COMPILE=$(CC) $(CFLAGS) -g
RM=rm -rf

INCLUDES=-I/usr/include/X11 -I$(ROOTDIR)/includes -I$(LIBFTX_DIR)/includes -I$(MLX_DIR)


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

# --------------

re: fclean all

# --------------

%.o: %.c
	@$(COMPILE) $(INCLUDES) -c $< -o $@

# ----UTILS-----
VALGRIND=@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes
valgrind: all
	@$(VALGRIND) ./$(NAME) $(mapfile)
valgrindre: re valgrind

download:
	@wget https://cdn.intra.42.fr/document/document/21656/minilibx-linux.tgz
	@tar -xf minilibx-linux.tgz
	@mv minilibx-linux $(ROOTDIR)/minilibx
	@$(RM) minilibx-linux.tgz

# ----OTHER-----
.PHONY: all clean fclean re valgrind
.SILENT:

# ----COLORS----
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
R=\033[0m
# --------------
