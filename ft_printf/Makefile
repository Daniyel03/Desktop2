# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 17:55:12 by dscholz           #+#    #+#              #
#    Updated: 2023/11/30 18:56:02 by dscholz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = checker.c \
	ft_numlen.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_strlen.c \
	p.c \
	x.c \
	xl.c \
	s.c \
	ft_printf.c 

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all