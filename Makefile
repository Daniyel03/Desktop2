.PHONY: all clean fclean re

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = five_less.c operations.c operations2.c radix.c split.c stack_utils.c stack.c utils.c itoa.c checker.c main.c
PRINTF = ft_printf/libftprintf.a
OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) -L./ft_printf/ -lftprintf -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	make clean -C ft_printf
	@rm -f $(OBJS) $(PRINTF)

fclean: clean
	make fclean -C ft_printf
	@rm -f $(NAME) $(PRINTF)

re: fclean all