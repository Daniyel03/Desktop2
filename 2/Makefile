NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = five_less.c \ operations.c \ operations2.c \ radix.c \ split.c \ stack_utils.c \ stack.c \ utils.c \ main.c

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

