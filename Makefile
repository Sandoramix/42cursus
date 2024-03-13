_MANDATORY=pipex
_BONUS=pipex_bonus

NAME=$(_MANDATORY)

PNAME = $(shell echo -n ${NAME} | tr 'a-z' 'A-Z')
PBONUSNAME = $(shell echo -n ${NAME} | tr 'a-z' 'A-Z')

# SRCS PATH
ROOTDIR = ./src
LIBFTX_DIR = $(ROOTDIR)/libftx

# COMPILATION SETTINGS
CC = cc
INCLUDES = -I$(ROOTDIR)/includes -I$(LIBFTX_DIR)/includes
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) $(DEBUGFLAGS)

# UTILS COMMANDS
RM = rm -rf

# --------------

SRC = ./src/px_child.c \
	./src/px_exit.c \
	./src/px_files.c \
	./src/px_utils.c

SRC_MANDATORY = $(SRC) ./main.c

SRC_BONUS = $(SRC) ./main_bonus.c

# ----RULES-----
all: $(NAME)

$(NAME): $(SRC_MANDATORY)
	$(MAKE) -C $(LIBFTX_DIR) DEBUGFLAGS=$(DEBUGFLAGS)
	$(CC) $(CFLAGS) $(SRC_MANDATORY) -o $(_MANDATORY) -L$(LIBFTX_DIR) -lft

	@echo "$(GREEN)[$(PNAME)]:\tPROGRAM CREATED$(R)"
	[ -z "$(strip $(DEBUGFLAGS))" ] || echo "$(RED)[$(PNAME)]:\tDEBUG MODE ENABLED$(R)"

bonus: $(_BONUS)

$(_BONUS): $(SRC_BONUS)
	$(MAKE) -C $(LIBFTX_DIR) DEBUGFLAGS=$(DEBUGFLAGS)
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(_BONUS) -L$(LIBFTX_DIR) -lft

	@echo "$(GREEN)[$(PBONUSNAME)]:\tPROGRAM CREATED:\t$(RED)BONUS!$(R)"
	[ -z "$(strip $(DEBUGFLAGS))" ] || echo "$(RED)[$(PNAME)]:\tDEBUG MODE ENABLED$(R)"


clean:
	@$(MAKE) -C $(LIBFTX_DIR) clean
	$(RM) .heredoc*

fclean: clean
	$(MAKE) -C $(LIBFTX_DIR) fclean
	@$(RM) $(_MANDATORY)
	@$(RM) $(_BONUS)
	@echo "$(BLUE)[$(PNAME)]:\tPROGRAM DELETED$(R)"

re: fclean all
bonus-re: fclean bonus

# ----UTILS-----
debug:
	$(MAKE) DEBUGFLAGS=-g
debug-bonus:
	$(MAKE) bonus DEBUGFLAGS=-g

re-debug: fclean debug
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
