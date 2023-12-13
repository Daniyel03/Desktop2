/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:35:13 by dscholz           #+#    #+#             */
/*   Updated: 2023/12/13 11:16:36 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	op;

	res = 0;
	op = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			op = op * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10;
		res = res + (*str - 48);
		str++;
	}
	return (op * res);
}

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

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && --n && str1[i] != '\0' && str2[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int ft_isdigit(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return 0;
	}
	return 1;
}
int max2(int count, char** arg)
{
	int i = count;
	while (count-- > 0) // pb with count when split or not 
    {
        char* convertedString = ft_itoa(ft_atoi(arg[count]));

        if (ft_strncmp(arg[count], convertedString, 11) != 0)
        {
            free(convertedString); // Free allocated memory
				while(i--)
					free(arg[i]);
				free(arg);
            	return 0;
		}
        else
        {
            free(convertedString); // Free allocated memory
        }
    }
	while(i--)
		free(arg[i]);
	free(arg);
	return 1;
}

int max(int count, char** arg)
{
	int i = 0;
	int flag = 0;
	if (count == 2 && !ft_isdigit(arg[1]))
	{
		arg = ft_split(arg[1], ' ');
		while (arg[i])
			i++;
		if (!max2(i, arg))
			return 0;
		else
			return 1;
	}
	count--;
		ft_printf("count: %d\n", count);
	// ft_printf("i: %d\n", i);
	while (count-- > 1) // pb with count when split or not  0 1
    {
        char* convertedString = ft_itoa(ft_atoi(arg[count]));

        if (ft_strncmp(arg[count], convertedString, 11) != 0)
        {
            // free(arg[count]);
            free(convertedString); // Free allocated memory
			if (flag)
			{
				while(i--)
					free(arg[i]);
				free(arg);
			}            // free(arg[count]);
        	return 0;
		}
        else
        {
            // free(arg[count]);
            free(convertedString); // Free allocated memory
        }
    }
	if (flag)
	{
		while(i--)
			free(arg[i]);
		free(arg);
	}
	return 1;
}


static int justnum(char **str)
{
	int i;
	int j;

	i = 1;
	while(str[i])
	{
		j = 0;
		while (str[i][j] == ' ')
			j++;
		if (str[i][j] == '\0')
			return (0);
		j = 0;
		while(str[i][j])
		{
			// ft_printf("str[i][j]: %c\n", str[i][j]);
			if ((str[i][j] >= '0' && str[i][j] <= '9') || (str[i][j] == '-' || str[i][j] == '+' || str[i][j] == ' '))
				j++;
			else
				return (0);
		}
		// ft_printf("i: %d\n", i);
		i++;
	}
	return 1;
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	if (!justnum(argv))
		return (ft_printf("schweizer1"), 0);
	if (!max(argc, argv))
		return (ft_printf("schweizer2"), 0);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	else
		argv = notsplit(argv, argc);
	if (!argv)
		return (0);
	stack = stopfer(argv);
	if (!asorted(stack))
		sorter(stack);
	free(stack->astack);
	free(stack->bstack);
	free(stack);
	stack = NULL;
	return (0);
}
