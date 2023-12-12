/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:49:45 by dscholz           #+#    #+#             */
/*   Updated: 2023/10/15 17:50:45 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p(unsigned long long n)
{
	int	counter;

	counter = 2;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (counter + 3);
	}
	write(1, "0x", 2);
	return ((unsigned long long)(counter += x(n, 16)));
}
