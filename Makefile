NAME = push_swap
CC = cc
SOURCES = push_swap.c

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $@ $^

%.o: %.c
	@$(CC) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

