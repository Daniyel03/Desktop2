/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:07:38 by dscholz           #+#    #+#             */
/*   Updated: 2023/11/30 18:39:15 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rid(t_stack *stack)
{
	free(stack->astack);
	free(stack->bstack);
	free(stack);
	ft_printf("ne diggah\n");
	exit(EXIT_FAILURE);
}

int	full(t_stack *stack, int top)
{
	if (stack->size == top)
		return (1);
	else
		return (0);
}

void	ft_aswap(t_stack *stack)
{
	int	temp1;
	int	temp2;

	temp1 = stack->astack[stack->atop];
	temp2 = stack->astack[stack->atop - 1];
	stack->astack[stack->atop] = temp2;
	stack->astack[stack->atop - 1] = temp1;
}

void	ft_bswap(t_stack *stack)
{
	int	temp1;
	int	temp2;

	temp1 = stack->bstack[stack->btop];
	temp2 = stack->bstack[stack->btop - 1];
	stack->bstack[stack->btop] = temp2;
	stack->bstack[stack->btop - 1] = temp1;
}

int	rrr(t_stack *stack)
{
	ft_printf("rrr\n");
	if (stack->atop < 1 || stack->btop < 1)
		return (0);
	rrb(stack);
	rra(stack);
	return (1);
}
