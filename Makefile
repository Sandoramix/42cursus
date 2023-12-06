NAME=so_long

ROOTDIR=./src
CC=cc
CFLAGS=-Wall -Werror -Wextra
COMPILE=$(CC) $(CFLAGS)
RM=rm -rf

FT_DIR=$(ROOTDIR)/libftx
ALL_INCLUDES=-I$(ROOTDIR)/includes -I$(FT_DIR)/includes

SRC= ./src/map_parsing/parsemap.c \
	./src/utils.c \
	./src/main.c \
	./src/map_parsing/inputctrl.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(COMPILE) $(ALL_INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C $(FT_DIR)
	@$(COMPILE) $(ALL_INCLUDES) $(OBJ) -L$(FT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)[SO_LONG]:\tPROGRAM CREATED SUCCESSFULLY$(R)"

clean:
	@$(RM) $(OBJ)
	$(MAKE) -C $(FT_DIR) clean

fclean: clean
	$(MAKE) -C $(FT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(BLUE)[SO_LONG]:\tPROGRAM DELETED$(R)"

re: fclean all



# ---COLORS---
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
R=\033[0m
# ------------

.PHONY: all clean fclean re
.SILENT: