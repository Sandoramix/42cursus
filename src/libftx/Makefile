NAME = libft.a
CC = cc
CEXTRAFLAGS=
CFLAGS = -Wall -Wextra -Werror $(CEXTRAFLAGS)
COMPILE = $(CC) $(CFLAGS)
ARCHIVE = ar rc $(NAME)
RM = rm -f

SRC = ./src/char/ft_charequals.c \
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
	./src/dl_list/dll_search.c \
	./src/dl_list/dll_utils.c \
	./src/files/ft_readfile.c \
	./src/getnextline/get_next_line.c \
	./src/getnextline/get_next_line_utils.c \
	./src/int/ft_int_minmax_idx.c \
	./src/int/ft_intcmp.c \
	./src/int/int_imin.c \
	./src/int/array/int_populate.c \
	./src/int/array/int_clear.c \
	./src/int/array/int_print.c \
	./src/int/array/int_search.c \
	./src/lists/ft_lstadd_back.c \
	./src/lists/ft_lstadd_front.c \
	./src/lists/ft_lstclear.c \
	./src/lists/ft_lstdelone.c \
	./src/lists/ft_lstiter.c \
	./src/lists/ft_lstlast.c \
	./src/lists/ft_lstmap.c \
	./src/lists/ft_lstnew.c \
	./src/lists/ft_lstsize.c \
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
	./src/str/ft_istrlen.c \
	./src/str/ft_str_freejoin.c \
	./src/str/ft_strchr.c \
	./src/str/ft_strcount_c.c \
	./src/str/ft_strdup.c \
	./src/str/ft_strendswith.c \
	./src/str/ft_strevery.c \
	./src/str/ft_stridxofchar.c \
	./src/str/ft_stridxofstr.c \
	./src/str/ft_striteri.c \
	./src/str/ft_strjoin.c \
	./src/str/ft_strlcat.c \
	./src/str/ft_strlcpy.c \
	./src/str/ft_strlen.c \
	./src/str/ft_strmapi.c \
	./src/str/ft_strmtxdup.c \
	./src/str/ft_strncmp.c \
	./src/str/ft_strnstr.c \
	./src/str/ft_strpad.c \
	./src/str/ft_strpushchar.c \
	./src/str/ft_strrchr.c \
	./src/str/ft_strreplace.c \
	./src/str/ft_strreplace_first.c \
	./src/str/ft_strsplit.c \
	./src/str/ft_strsubstr.c \
	./src/str/ft_strtolower.c \
	./src/str/ft_strtoupper.c \
	./src/str/ft_strtrim.c \
	./src/strict/converter/strict_atoi.c \
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
	@$(COMPILE) -c $< -o $@ -Iincludes
	@echo "$(BLUE)[LIBFTX]:\t$< COMPILED!"

$(NAME): $(OBJ)
	@$(ARCHIVE) $(OBJ)
	@echo "$(GREEN)[LIBFTX]:\tLIBRARY CREATED$(R)"

clean:
	@$(RM) $(OBJ)
	@echo "$(RED)[LIBFTX]:\tOBJECTS DELETED$(R)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)[LIBFTX]:\tLIBRARY DELETED$(R)"

re: fclean all

debug:
	$(MAKE) CEXTRAFLAGS=-g
debug-re: fclean debug

# COLORS
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
R=\033[0m

.PHONY: all clean fclean re
.SILENT: