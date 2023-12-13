NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SOURCES = five_less.c \ operations.c \ operations2.c \ radix.c \ split.c \ stack_utils.c \ stack.c \ utils.c \ itoa.c \ main.c
PRINTF = ft_printf/libftprintf.a
OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTF)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJS) $(PRINTF)

fclean: clean
	@rm -f $(NAME) $(PRINTF)

re: fclean all