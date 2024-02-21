_MANDATORY=pipex
_BONUS=pipex_bonus

# EXECUTABLE NAME
ifeq ($(BONUS_FLAGS), )
NAME=$(_MANDATORY)
else
NAME=$(_BONUS)
endif
PNAME = $(shell echo -n ${NAME} | tr 'a-z' 'A-Z')

# SRCS PATH
ROOTDIR = ./src
LIBFTX_DIR = $(ROOTDIR)/libftx

# COMPILATION SETTINGS
CC = cc
INCLUDES = -I$(ROOTDIR)/includes -I$(LIBFTX_DIR)/includes
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) $(DEBUGFLAGS) $(BONUS_FLAGS)

# UTILS COMMANDS
RM = rm -rf

# --------------

#SRCS
SRC = main.c

# ----RULES-----
all: $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C $(LIBFTX_DIR) DEBUGFLAGS=$(DEBUGFLAGS)
	@echo "$(GREEN)[$(PNAME)]:\tPROGRAM CREATED$(R)"
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -L$(LIBFTX_DIR) -lft
	[ -z "$(strip $(BONUS_FLAGS))" ] || echo "$(RED)[$(PNAME)]:\tBONUS!$(R)"
	[ -z "$(strip $(DEBUGFLAGS))" ] || echo "$(RED)[$(PNAME)]:\tDEBUG MODE ENABLED$(R)"

clean:
	@$(MAKE) -C $(LIBFTX_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFTX_DIR) fclean
	@$(RM) $(_MANDATORY)
	@$(RM) $(_BONUS)
	@echo "$(BLUE)[$(PNAME)]:\tPROGRAM DELETED$(R)"

bonus:
	make BONUS_FLAGS="-DBONUS=1" DEBUGFLAGS=$(DEBUGFLAGS)

re: fclean all
bonus-re: fclean bonus

# ----UTILS-----
debug:
	$(MAKE) DEBUGFLAGS=-g
debug-bonus:
	$(MAKE) bonus DEBUGFLAGS=-g

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