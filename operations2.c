/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:35:39 by dscholz           #+#    #+#             */
/*   Updated: 2023/12/14 13:38:24 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *stack)
{
	int	temp1;
	int	temp2;
	int	count;

	ft_printf("ra\n");
	count = stack->atop;
	if (stack->atop < 1)
		return (0);
	while (count > 0)
	{
		temp1 = stack->astack[count];
		temp2 = stack->astack[count - 1];
		stack->astack[count] = temp2;
		stack->astack[count - 1] = temp1;
		count--;
	}
	return (1);
}

int	rb(t_stack *stack)
{
	int	temp1;
	int	temp2;
	int	count;

	ft_printf("rb\n");
	count = stack->btop;
	if (stack->btop < 1)
		return (0);
	while (count > 0)
	{
		temp1 = stack->bstack[count];
		temp2 = stack->bstack[count - 1];
		stack->bstack[count] = temp2;
		stack->bstack[count - 1] = temp1;
		count--;
	}
	return (1);
}

int	rr(t_stack *stack)
{
	ft_printf("rr\n");
	if (stack->atop < 1 || stack->btop < 1)
		return (0);
	rb(stack);
	ra(stack);
	return (1);
}

int	rra(t_stack *stack)
{
	int	temp1;
	int	temp2;
	int	count;

	ft_printf("rra\n");
	count = 0;
	if (stack->atop < 1)
		return (0);
	while (count < stack->atop)
	{
		temp1 = stack->astack[count];
		temp2 = stack->astack[count + 1];
		stack->astack[count] = temp2;
		stack->astack[count + 1] = temp1;
		count++;
	}
	return (1);
}

int	rrb(t_stack *stack)
{
	int	temp1;
	int	temp2;
	int	count;

	ft_printf("rrb\n");
	count = 0;
	if (stack->btop < 1)
		return (0);
	while (count < stack->btop)
	{
		temp1 = stack->bstack[count];
		temp2 = stack->bstack[count + 1];
		stack->bstack[count] = temp2;
		stack->bstack[count + 1] = temp1;
		count++;
	}
	return (1);
}
