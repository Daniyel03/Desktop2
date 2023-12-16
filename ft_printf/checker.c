/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:16:12 by dscholz           #+#    #+#             */
/*   Updated: 2023/10/15 17:28:12 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checker2(const char *str, va_list arg, int ccount)
{
	unsigned int	num;

	if (*str == 'u')
	{
		num = va_arg(arg, int);
		ft_putnbr_fd(num, 1);
		ccount = ft_numlen(num);
	}
	else if (*str == 'x')
		ccount = x(va_arg(arg, unsigned int), 16);
	else if (*str == 'X')
		ccount = xl(va_arg(arg, unsigned int), 16);
	else if (*str == 'p')
		ccount = p(va_arg(arg, unsigned long));
	else
		write(1, str, 1);
	return (ccount);
}

int	checker(const char *str, va_list arg)
{
	int			ccount;
	long long	num;

	ccount = 1;
	if (*str == '\0')
		return (-1);
	if (*str == '%')
		write(1, str, 1);
	else if (*str == 'c')
		ft_putchar_fd(va_arg(arg, int), 1);
	else if (*str == 's')
		ccount = s(va_arg(arg, char *));
	else if (*str == 'd' || *str == 'i')
	{
		num = va_arg(arg, int);
		ft_putnbr_fd(num, 1);
		ccount = ft_numlen(num);
	}
	else
		return (checker2(str, arg, ccount));
	return (ccount);
}
