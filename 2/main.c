/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:35:13 by dscholz           #+#    #+#             */
/*   Updated: 2023/11/17 22:11:21 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	doublechecker(int *num, t_stack *stack)
{
	int	i;
	int	j;
	int	count;

	count = stack->size;
	j = 0;
	i = 0;
	while (i < count)
	{
		j = (i + 1);
		while (j < count)
		{
			if (num[i] == num[j++])
				return (1);
		}
		i++;
	}
	return (0);
}

int	sorter(t_stack *stack)
{
	if (stack->atop == 1)
		sa(stack);
	else if (stack->atop == 2)
		three(stack);
	else if (stack->atop == 3)
		four(stack);
	else if (stack->atop == 4)
		five(stack);
	else
		radix(stack);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	else
		argv = notsplit(argv, argc);
	if (!argv)
		return (0);
	stack = stopfer(argv);
	sorter(stack);
	// int i = 0;
	free(stack->astack);
	free(stack->bstack);
	free(stack);
	stack = NULL;
	// argv = NULL;
	// free(argv);
	return (0);
}
