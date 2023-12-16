/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:44:06 by dscholz           #+#    #+#             */
/*   Updated: 2023/12/14 18:44:14 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	max2(int count, char **arg)
{
	int		i;
	char	*str;

	i = count;
	while (count-- > 0)
	{
		str = ft_itoa(ft_atoi(arg[count]));
		if (ft_strncmp(arg[count], str, 11) != 0)
		{
			free(str);
			while (i--)
				free(arg[i]);
			free(arg);
			return (0);
		}
		else
			free(str);
	}
	while (i--)
		free(arg[i]);
	free(arg);
	return (1);
}

int	max1(int count, char **arg)
{
	char	*str;

	count--;
	while (count-- > 1)
	{
		str = ft_itoa(ft_atoi(arg[count]));
		if (ft_strncmp(arg[count], str, 11) != 0)
		{
			free(str);
			return (0);
		}
		else
			free(str);
	}
	return (1);
}

int	max(int count, char **arg)
{
	int	i;

	i = 0;
	if (count == 2 && !ft_isdigit(arg[1]))
	{
		arg = ft_split(arg[1], ' ');
		while (arg[i])
			i++;
		if (!max2(i, arg))
			return (0);
		else
			return (1);
	}
	else if (!max1(count, arg))
		return (0);
	return (1);
}

int	justnum(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j] == ' ')
			j++;
		if (str[i][j] == '\0')
			return (0);
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] >= '0' && str[i][j] <= '9') ||
				(str[i][j] == '-' || str[i][j] == '+' || str[i][j] == ' '))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
