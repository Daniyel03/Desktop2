/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:37:18 by dscholz           #+#    #+#             */
/*   Updated: 2023/11/30 17:52:33 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm(t_stack *stack, int *sorted)
{
	int	i;
	int	j;
	int	*cpy;

	i = -1;
	j = 0;
	cpy = malloc(sizeof(int) * stack->size);
	if (!cpy)
		rid(stack);
	cpy = cpyarr(stack->astack, cpy, stack->size);
	while (++i < stack->size)
	{
		j = -1;
		while (j < stack->size)
		{
			if (sorted[i] == cpy[++j])
			{
				stack->astack[j] = (i + 1);
				break ;
			}
		}
	}
	free(cpy);
	cpy = NULL;
}

int	*comp(t_stack *stack, int *cpy, int i, int j)
{
	int	tmp;

	tmp = 0;
	while (i < (stack->size - 1))
	{
		j = (i + 1);
		while (j < stack->size)
		{
			if (cpy[i] > cpy[j])
			{
				tmp = cpy[i];
				cpy[i] = cpy[j];
				cpy[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (cpy);
}

void	normalizer(t_stack *stack)
{
	int	i;
	int	j;
	int	*cpy;

	i = 0;
	j = 0;
	cpy = malloc(sizeof(int) * stack->size);
	if (!cpy)
	{
		free(cpy);
		rid(stack);
	}
	cpy = cpyarr(stack->astack, cpy, stack->size);
	cpy = comp(stack, cpy, i, j);
	norm(stack, cpy);
	free(cpy);
	cpy = NULL;
}

void	stabler(t_stack *stack, char **argv)
{
	int	count;
	int	stackk;
	int	i;

	count = 0;
	stackk = (stack->size - 1);
	while (count < (stack->size))
	{
		stack->astack[stackk] = ft_atoi(argv[count]);
		count++;
		stackk--;
	}
	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	argv = NULL;
	if (doublechecker(stack->astack, stack))
		rid(stack);
	normalizer(stack);
}

t_stack	*stopfer(char **argv)
{
	int		i;
	t_stack	*stack;

	i = 0;
	while (argv[i])
		i++;
	if (!i)
		return (NULL);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->astack = malloc(sizeof(int) * i);
	stack->bstack = malloc(sizeof(int) * i);
	if (!stack->astack || !stack->bstack)
	{
		free(stack);
		return (NULL);
	}
	stack->atop = i - 1;
	stack->btop = -1;
	stack->size = i;
	stabler(stack, argv);
	return (stack);
}
