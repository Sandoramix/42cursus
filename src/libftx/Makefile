NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c
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
	./src/files/ft_readfile.c \
	./src/getnextline/get_next_line.c \
	./src/getnextline/get_next_line_utils.c \
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
	./src/str/ft_istrlen.c \
	./src/str/ft_str_freejoin.c \
	./src/str/ft_strchr.c \
	./src/str/ft_strcount_c.c \
	./src/str/ft_strdup.c \
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
	./src/str/ft_strendswith.c \
	./src/str/ft_strtrim.c \
	./src/unistd/ft_putaddr_fd.c \
	./src/unistd/ft_putchar_fd.c \
	./src/unistd/ft_putendl_fd.c \
	./src/unistd/ft_perror.c \
	./src/unistd/ft_putnchars_fd.c \
	./src/unistd/ft_putnbr_fd.c \
	./src/unistd/ft_putstr_fd.c \
	./src/unistd/ft_putstrmtx.c \
	./src/unistd/ft_writeulbase_fd.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

%.o: %.c
	@$(COMPILE) $< -o $@ -Iincludes
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


printfmain: all
	@$(CC) -w -Iincludes ft_printfm.c -L. -lft
gnlmain: all
	@$(CC) -w -Iincludes gnl_main.c -L. -lft
readfilemain: all
	@$(CC) -w -Iincludes readfile_main.c -L. -lft

test: all
	@$(CC) -w -Iincludes test.c -L. -lft

# COLORS
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
R=\033[0m

.PHONY: all clean fclean re
.SILENT: