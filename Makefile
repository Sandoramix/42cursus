NAME=so_long

ROOTDIR=./src
CC=cc
CFLAGS=-Wall -Werror -Wextra
COMPILE=$(CC) $(CFLAGS)
RM=rm -rf



FT_DIR=$(ROOTDIR)/libftx
ALL_INCLUDES=-I$(ROOTDIR)/includes -I$(FT_DIR)/includes

MAINSRC=$(ROOTDIR)/main.c

SRC= ./src/map_parsing/parsemap.c \
	./src/utils.c \

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(MAKE) -C $(FT_DIR)
	$(COMPILE) $(MAINSRC) $(SRC) -L$(FT_DIR) -lft $(ALL_INCLUDES) -o $(NAME)
	@echo "$(GREEN)[SO_LONG]:\tPROGRAM CREATED SUCCESSFULLY$(R)"

clean:
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

.PHONY: re all $(NAME) clean fclean
.SILENT: