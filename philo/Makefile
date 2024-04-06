NAME=philo
PNAME = $(shell echo -n ${NAME} | tr 'a-z' 'A-Z')

CC = cc
INCLUDES = -Iincludes
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) $(DEBUGFLAGS)

RM = rm -rf

# --------------
SRC = ./main.c \
	./utils/checks.c \
	./utils/jobs.c \
	./utils/init.c \
	./utils/mutex/mutex_getters.c \
	./utils/mutex/mutex_increments.c \
	./utils/mutex/mutex_setters.c \
	./utils/mutex/mutex_wrapper.c \
	./utils/other.c \
	./utils/pthread/pthread_wrapper.c \
	./utils/sys/sys_time.c \
	./utils/utils.c


# ----RULES-----
all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -pthread -o $(NAME)

	@echo "$(GREEN)[$(PNAME)]:\tPROGRAM CREATED$(R)"
	[ -z "$(strip $(DEBUGFLAGS))" ] || echo "$(RED)[$(PNAME)]:\tDEBUG MODE ENABLED$(R)"

clean:

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)[$(PNAME)]:\tPROGRAM DELETED$(R)"

re: fclean all

# ----UTILS-----
re-debug-log: fclean debug-log
re-debug: fclean debug

debug:
	$(MAKE) DEBUGFLAGS="-g"
debug-log:
	$(MAKE) DEBUGFLAGS="-g -DDEBUG=true"
# --------------
.PHONY: all clean fclean re valgrind
.SILENT:

# ----COLORS----
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
R=\033[0m