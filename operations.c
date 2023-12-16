/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:35:28 by dscholz           #+#    #+#             */
/*   Updated: 2023/11/30 19:12:33 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack)
{
	ft_printf("sa\n");
	if (stack->atop < 1)
		return (0);
	ft_aswap(stack);
	return (1);
}

int	sb(t_stack *stack)
{
	ft_printf("sb\n");
	if (stack->btop < 1)
		return (0);
	ft_bswap(stack);
	return (1);
}

int	ss(t_stack *stack)
{
	ft_printf("ss\n");
	if (stack->atop < 1 || stack->btop < 1)
		return (0);
	ft_aswap(stack);
	ft_bswap(stack);
	return (1);
}

int	pb(t_stack *stack)
{
	int	temp1;
	int	one;

	ft_printf("pb\n");
	if (stack->atop == -1 || full(stack, stack->btop))
		return (0);
	one = (stack->btop + 1);
	stack->btop = one;
	temp1 = stack->astack[stack->atop];
	stack->bstack[stack->btop] = temp1;
	one = (stack->atop - 1);
	stack->atop = one;
	return (1);
}

int	pa(t_stack *stack)
{
	int	temp1;
	int	one;

	ft_printf("pa\n");
	if (stack->btop == -1 || full(stack, stack->atop))
		return (0);
	one = (stack->atop + 1);
	temp1 = stack->bstack[stack->btop];
	stack->astack[stack->atop + 1] = temp1;
	stack->atop = one;
	one = (stack->btop - 1);
	stack->btop = one;
	return (1);
}
