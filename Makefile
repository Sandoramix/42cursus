_MANDATORY=pipex
_BONUS=pipex_bonus

NAME=$(_MANDATORY)

PNAME = $(shell echo -n ${NAME} | tr 'a-z' 'A-Z')
PBONUSNAME = $(shell echo -n ${NAME} | tr 'a-z' 'A-Z')

# SRCS PATH
ROOTDIR = ./src
LIBFTX_DIR = $(ROOTDIR)/libftx

# COMPILATION SETTINGS
DEBUG_VALUE=0
debug: DEBUG_VALUE=1
re-debug: DEBUG_VALUE=1
re-bonus-debug: DEBUG_VALUE=1
bonus-debug: DEBUG_VALUE=1

CC = cc
INCLUDES = -I$(ROOTDIR)/includes -I$(LIBFTX_DIR)/includes
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -DDEBUG$(DEBUG_VALUE) -g

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
debug: $(NAME)

$(NAME): $(SRC_MANDATORY)
	$(MAKE) -C $(LIBFTX_DIR) DEBUG_VALUE=$(DEBUG_VALUE)
	$(CC) $(CFLAGS) $(SRC_MANDATORY) -o $(_MANDATORY) -L$(LIBFTX_DIR) -lft

	@echo "$(GREEN)[$(PNAME)]:\tPROGRAM CREATED$(R)"
	[ "$(strip $(DEBUG_VALUE))" = "0" ] || echo "$(RED)[$(PNAME)]:\tDEBUG MODE ENABLED$(R)"

bonus: $(_BONUS)
bonus-debug: $(_BONUS)

$(_BONUS): $(SRC_BONUS)
	$(MAKE) -C $(LIBFTX_DIR) DEBUG_VALUE=$(DEBUG_VALUE)
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(_BONUS) -L$(LIBFTX_DIR) -lft

	@echo "$(GREEN)[$(PBONUSNAME)]:\tPROGRAM CREATED:\t$(RED)BONUS!$(R)"
	[ "$(strip $(DEBUG_VALUE))" = "0" ] || echo "$(RED)[$(PNAME)]:\tDEBUG MODE ENABLED$(R)"


clean:
	@$(MAKE) -C $(LIBFTX_DIR) clean
	$(RM) .heredoc*

fclean: clean
	$(MAKE) -C $(LIBFTX_DIR) fclean
	@$(RM) $(_MANDATORY)
	@$(RM) $(_BONUS)
	@echo "$(BLUE)[$(PNAME)]:\tPROGRAM DELETED$(R)"

re: fclean all
re-bonus: fclean bonus
re-debug: fclean debug
re-bonus-debug: fclean bonus-debug

# ----UTILS-----
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
