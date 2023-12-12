/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:55:45 by dscholz           #+#    #+#             */
/*   Updated: 2023/11/30 20:11:17 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		checker(const char *str, va_list arg);
long	ft_numlen(long res);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(long n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);
int		p(unsigned long long n);
int		x(unsigned long long n, int base);
int		xl(unsigned long n, int base);
int		s(char *s);
int		ft_printf(const char *str, ...);

#endif