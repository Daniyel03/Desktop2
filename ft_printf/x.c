/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:51:01 by dscholz           #+#    #+#             */
/*   Updated: 2023/10/15 17:52:28 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x(unsigned long long n, int base)
{
	int		counter;
	char	*chars;

	chars = "0123456789abcdef";
	counter = 1;
	if (n < (unsigned long long)base)
		ft_putchar_fd(chars[n], 1);
	else
	{
		counter = x(n / (unsigned long long)base, base);
		counter += x(n % (unsigned long long)base, base);
	}
	return (counter);
}
