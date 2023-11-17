/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:53:44 by dscholz           #+#    #+#             */
/*   Updated: 2023/11/17 22:18:51 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ptr;
	int		i;

	i = 0;
	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	**notsplit(char **s, int argc)
{
	int		i;
	char	**argvv;

	i = (argc - 2);
	argvv = (char **)malloc(argc * sizeof(char *));
	argvv[argc - 1] = NULL;
	if (!argvv)
	{
		free(argvv);
		return (0);
	}
	argc--;
	while (i >= 0)
	{
		argvv[i] = ft_strdup(s[argc]);
		i--;
		argc--;
	}
	return (argvv);
}

int	ft_strcmp(int s1, int s2)
{
	while (s1 == s2 && s1)
	{
		s1++;
		s2++;
	}
	return (s1 - s2);
}

int	*cpyarr(int *arr, int *cpy, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}
