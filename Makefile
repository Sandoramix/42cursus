NAME = get_next_line

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -c -o $@ $< -I.

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
