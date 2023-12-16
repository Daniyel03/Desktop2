/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:45:39 by dscholz           #+#    #+#             */
/*   Updated: 2023/10/15 17:46:57 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	arg;

	if (!str)
		return (-1);
	count = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			count++;
			str++;
		}
		else
		{
			str++;
			count += checker(str, arg);
			str++;
		}
	}
	va_end(arg);
	return (count);
}
