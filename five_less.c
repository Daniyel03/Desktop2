/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:34:57 by dscholz           #+#    #+#             */
/*   Updated: 2023/12/14 16:45:25 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	asorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->atop)
	{
		if (!(ft_strcmp(stack->astack[i], stack->astack[i + 1]) == 1))
			return (0);
		i++;
	}
	return (1);
}

int	bsorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->btop)
	{
		if (!(ft_strcmp(stack->bstack[i], stack->bstack[i + 1]) == 1))
			return (0);
		i++;
	}
	return (1);
}

void	three(t_stack *stack)
{
	if (stack->astack[2] == 2 && stack->astack[1] == 3
		&&stack->astack[0] == 1)
		rra(stack);
	else if (stack->astack[2] == 3 && stack->astack[1] == 1
		&& stack->astack[0] == 2)
		ra(stack);
	else if (stack->astack[2] == 1 && stack->astack[1] == 3
		&& stack->astack[0] == 2)
	{
		sa(stack);
		ra(stack);
	}
	else if (stack->astack[2] == 2 && stack->astack[1] == 1
		&& stack->astack[0] == 3)
		sa(stack);
	else if (stack->astack[2] == 3 && stack->astack[1] == 2
		&& stack->astack[0] == 1)
	{
		ra(stack);
		sa(stack);
	}
}

void	four(t_stack *stack)
{
	while (stack->astack[stack->atop] != 4)
		rra(stack);
	pb(stack);
	three(stack);
	pa(stack);
	ra(stack);
}

void	five(t_stack *stack)
{
	int	count;

	count = 0;
	while (count != 2)
	{
		if (stack->astack[stack->atop] == 4 || stack->astack[stack->atop] == 5)
		{
			pb(stack);
			count++;
		}
		if (count == 2)
			break ;
		rra(stack);
	}
	if (bsorted(stack))
		sb(stack);
	three(stack);
	pa(stack);
	pa(stack);
	ra(stack);
	ra(stack);
}
