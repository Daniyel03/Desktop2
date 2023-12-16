/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:52:42 by dscholz           #+#    #+#             */
/*   Updated: 2023/10/15 17:53:46 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	xl(unsigned long n, int base)
{
	int		counter;
	char	*charss;

	charss = "0123456789ABCDEF";
	counter = 1;
	if (n < (unsigned long)base)
		ft_putchar_fd(charss[n], 1);
	else
	{
		counter = xl(n / (unsigned long)base, base);
		counter += xl(n % (unsigned long)base, base);
	}
	return (counter);
}
