NAME = libft.a
PNAME = [LIBFTX]

CC = cc
CFLAGS = -Wall -Wextra -Werror $(DEBUGFLAGS)
COMPILE = $(CC) $(CFLAGS)
ARCHIVE = ar rc $(NAME)
RM = rm -f

SRC = ./src/char/chr_isquote.c \
	./src/char/ft_charequals.c \
	./src/char/ft_ctolower.c \
	./src/char/ft_ctoupper.c \
	./src/converter/ft_atoi.c \
	./src/converter/ft_boolstr.c \
	./src/converter/ft_itoa.c \
	./src/converter/ft_itoa_base.c \
	./src/converter/ft_itohex.c \
	./src/converter/ft_uitoa.c \
	./src/converter/ft_ultoa_base.c \
	./src/ctype/ft_isalnum.c \
	./src/ctype/ft_isalpha.c \
	./src/ctype/ft_isascii.c \
	./src/ctype/ft_isdigit.c \
	./src/ctype/ft_isprint.c \
	./src/ctype/ft_issign.c \
	./src/ctype/ft_isspace.c \
	./src/dl_list/dll_create.c \
	./src/dl_list/dll_delete.c \
	./src/dl_list/dll_print.c \
	./src/dl_list/dll_search.c \
	./src/dl_list/dll_utils.c \
	./src/env/env_load.c \
	./src/env/env_search.c \
	./src/files/file_gen.c \
	./src/files/file_utils.c \
	./src/files/ft_readfile.c \
	./src/getnextline/get_next_line.c \
	./src/getnextline/get_next_line_utils.c \
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
	./src/lists/lst_get.c \
	./src/lists/lst_print.c \
	./src/lists/lst_search.c \
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
	./src/memory/ft_memmtxcpy.c \
	./src/memory/ft_memmtxlen.c \
	./src/memory/ft_memrev.c \
	./src/memory/ft_memset.c \
	./src/printf/ft_pfflag.c \
	./src/printf/ft_pflaghandler.c \
	./src/printf/ft_printf.c \
	./src/printf/ft_printf_core.c \
	./src/printf/pf_errcode.c \
	./src/str/str_chr.c \
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
	./src/str/str_isblank.c \
	./src/str/str_iteri.c \
	./src/str/str_join.c \
	./src/str/str_lcat.c \
	./src/str/str_lcpy.c \
	./src/str/str_mapi.c \
	./src/str/str_mtxdup.c \
	./src/str/str_nstr.c \
	./src/str/str_pad.c \
	./src/str/str_pushchar.c \
	./src/str/str_rchr.c \
	./src/str/str_replace.c \
	./src/str/str_replace_first.c \
	./src/str/str_split.c \
	./src/str/str_substr.c \
	./src/str/str_tolower.c \
	./src/str/str_toupper.c \
	./src/str/str_trim.c \
	./src/str/str_ulen.c \
	./src/strict/converter/strict_atoi.c \
	./src/sys/cmd_parseargs.c \
	./src/sys/sys_cmd.c \
	./src/unistd/ft_putaddr_fd.c \
	./src/unistd/ft_putchar_fd.c \
	./src/unistd/ft_putendl_fd.c \
	./src/unistd/ft_putnbr_fd.c \
	./src/unistd/ft_putnchars_fd.c \
	./src/unistd/ft_putstr_fd.c \
	./src/unistd/ft_putstrmtx.c \
	./src/unistd/ft_writeulbase_fd.c


OBJ = ${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	@$(COMPILE) -Iincludes -c $< -o $@
	@echo "$(BLUE)$(PNAME):\t$< COMPILED!"

$(NAME): $(OBJ)
	@$(ARCHIVE) $(OBJ)
	@echo "$(GREEN)$(PNAME):\tLIBRARY CREATED$(R)"
	[ -z "$(strip $(DEBUGFLAGS))" ] || echo "$(RED)$(PNAME):\tDEBUG MODE ENABLED$(R)"
clean:
	@$(RM) $(OBJ)
	@echo "$(RED)$(PNAME):\tOBJECTS DELETED$(R)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(PNAME):\tLIBRARY DELETED$(R)"

re: fclean all

debug:
	$(MAKE) DEBUGFLAGS=-g
debug-re: fclean debug

# COLORS
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
R=\033[0m

.PHONY: all clean fclean re
.SILENT: