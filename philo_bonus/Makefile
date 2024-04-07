NAME=philo_bonus
PNAME = $(shell echo -n ${NAME} | tr 'a-z' 'A-Z')

CC = cc
INCLUDES = -Iincludes
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) $(DEBUGFLAGS)

RM = rm -rf

# --------------
SRC = ./main.c \
	./src/checks.c \
	./src/init.c \
	./src/jobs.c \
	./src/other.c \
	./src/pthread/pthread_wrapper.c \
	./src/semaphore/sem_wrapper.c \
	./src/sys/sys_time.c \
	./src/utils.c


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
.PHONY: all clean fclean re
.SILENT:

# ----COLORS----
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
R=\033[0m