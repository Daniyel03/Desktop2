/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:35:53 by dscholz           #+#    #+#             */
/*   Updated: 2023/11/17 17:36:26 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bits(int num)
{
	int	count;

	count = 0;
	while (num)
	{
		count++;
		num >>= 1;
	}
	return (count);
}

void	radix(t_stack *stack)
{
	int	i;
	int	shift;
	int	count;
	int	temp;

	i = 0;
	shift = 0;
	count = bits(stack->size);
	while (shift < count)
	{
		i = 0;
		while (i < (stack->size))
		{
			temp = stack->astack[stack->atop];
			temp = temp >> shift;
			if ((temp & 1) == 0)
				pb(stack);
			else
				ra(stack);
			i++;
		}
		while (stack->btop != -1)
			pa(stack);
		shift++;
	}
}
