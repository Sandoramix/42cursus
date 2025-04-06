NAME = libft.a
PNAME = [LIBFTX]

# -----VARIABLES-DECLARATIONS-+-OVVERRIDES-----
DEBUG_VALUE=0

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -DDEBUG=$(DEBUG_VALUE)

ARCHIVE = ar rc $(NAME)

RM = rm -f

# ----SOURCE-FILES----
SRC = ./src/char/chr_closequote_idx.c \
	./src/char/chr_equals.c \
	./src/char/chr_isalnum.c \
	./src/char/chr_isalpha.c \
	./src/char/chr_isascii.c \
	./src/char/chr_isdigit.c \
	./src/char/chr_isprint.c \
	./src/char/chr_isquote.c \
	./src/char/chr_issign.c \
	./src/char/chr_isspace.c \
	./src/char/chr_istoken.c \
	./src/char/chr_tolower.c \
	./src/char/chr_toupper.c \
	./src/cleanup.c \
	./src/cmd/cmd_split_args.c \
	./src/converter/ft_atoi.c \
	./src/converter/ft_boolstr.c \
	./src/converter/ft_itoa.c \
	./src/converter/ft_itoa_base.c \
	./src/converter/ft_itohex.c \
	./src/converter/ft_uitoa.c \
	./src/converter/ft_ultoa_base.c \
	./src/env/env_load.c \
	./src/env/env_search.c \
	./src/files/file_gen.c \
	./src/files/file_utils.c \
	./src/files/ft_readfile.c \
	./src/ft_isdebug.c \
	./src/getnextline/get_next_line.c \
	./src/int/array/int_clear.c \
	./src/int/array/int_populate.c \
	./src/int/array/int_print.c \
	./src/int/array/int_search.c \
	./src/int/ft_int_minmax_idx.c \
	./src/int/ft_intcmp.c \
	./src/int/int_free.c \
	./src/int/int_imin.c \
	./src/lists/lst_count.c \
	./src/lists/lst_create.c \
	./src/lists/lst_delete.c \
	./src/lists/lst_delete2.c \
	./src/lists/lst_get.c \
	./src/lists/lst_print.c \
	./src/lists/lst_search.c \
	./src/lists/lst_split.c \
	./src/lists/lst_to_strmtx.c \
	./src/lists/lst_upsert.c \
	./src/math/ft_iabs.c \
	./src/math/ft_ipow.c \
	./src/math/ft_nbr_len.c \
	./src/math/ft_ulnbr_len.c \
	./src/memory/ft_bzero.c \
	./src/memory/ft_calloc.c \
	./src/memory/ft_free.c \
	./src/memory/ft_freemtx.c \
	./src/memory/ft_getaddr.c \
	./src/memory/ft_memchr.c \
	./src/memory/ft_memcmp.c \
	./src/memory/ft_memcpy.c \
	./src/memory/ft_memmove.c \
	./src/memory/ft_memrev.c \
	./src/memory/ft_memset.c \
	./src/printf/ft_pfflag.c \
	./src/printf/ft_pflaghandler.c \
	./src/printf/ft_printf.c \
	./src/printf/ft_printf_core.c \
	./src/printf/pf_errcode.c \
	./src/pthread/mutex/mutex_getters.c \
	./src/pthread/mutex/mutex_increments.c \
	./src/pthread/mutex/mutex_setters.c \
	./src/pthread/mutex/mutex_wrapper.c \
	./src/str/str_chr.c \
	./src/str/str_clearquotes.c \
	./src/str/str_cmp.c \
	./src/str/str_count_c.c \
	./src/str/str_dup.c \
	./src/str/str_endswith.c \
	./src/str/str_equals.c \
	./src/str/str_every.c \
	./src/str/str_freejoin.c \
	./src/str/str_idxofchar.c \
	./src/str/str_idxofstr.c \
	./src/str/str_ilen.c \
	./src/str/str_includesset.c \
	./src/str/str_isblank.c \
	./src/str/str_ischar_inquotes.c \
	./src/str/str_isvariable.c \
	./src/str/str_iteri.c \
	./src/str/str_join.c \
	./src/str/str_lcat.c \
	./src/str/str_lcpy.c \
	./src/str/str_mapi.c \
	./src/str/str_mtxcpy.c \
	./src/str/str_mtxdup.c \
	./src/str/str_mtxlen.c \
	./src/str/str_mtxpush.c \
	./src/str/str_nextidx.c \
	./src/str/str_nstr.c \
	./src/str/str_pad.c \
	./src/str/str_pushchar.c \
	./src/str/str_rchr.c \
	./src/str/str_replace.c \
	./src/str/str_replace_first.c \
	./src/str/str_split.c \
	./src/str/str_startswith.c \
	./src/str/str_substr.c \
	./src/str/str_tolower.c \
	./src/str/str_toupper.c \
	./src/str/str_trim.c \
	./src/str/str_ulen.c \
	./src/str/str_var_ending_idx.c \
	./src/strict/strict_atoi.c \
	./src/sys/sys_findcmdpath.c \
	./src/sys/sys_load_cmds.c \
	./src/sys/sys_time.c \
	./src/unistd/ft_putaddr_fd.c \
	./src/unistd/ft_putchar_fd.c \
	./src/unistd/ft_putendl_fd.c \
	./src/unistd/ft_putnbr_fd.c \
	./src/unistd/ft_putnchars_fd.c \
	./src/unistd/ft_putstr_fd.c \
	./src/unistd/ft_putstrmtx.c \
	./src/unistd/ft_writeulbase_fd.c

OBJ = ${SRC:.c=.o}

# ----RULES-----

all: $(NAME)

debug: DEBUG_VALUE=1
debug: all

$(NAME): $(OBJ)
	@$(ARCHIVE) $(OBJ)
	@echo "$(GREEN)$(PNAME):\tLIBRARY CREATED$(R)"
	[ "$(strip $(DEBUG_VALUE))" = "0" ] || echo "$(RED)[$(PNAME)]:\tDEBUG MODE ENABLED$(R)"
clean:
	@$(RM) $(OBJ)
	@echo "$(RED)$(PNAME):\tOBJECTS DELETED$(R)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(PNAME):\tLIBRARY DELETED$(R)"

re: fclean all
re-debug: fclean debug

# ----RULE-UTILS-----

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)$(PNAME):\t$< COMPILED!"

# --------------

.PHONY: all clean fclean re
.SILENT:

# ----COLORS----
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
R=\033[0m
