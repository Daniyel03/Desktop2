/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:37:10 by dscholz           #+#    #+#             */
/*   Updated: 2023/11/17 17:55:57 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	subcounter(const char *s, char c)
{
	int	subs;

	subs = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			subs++;
		while (*s && *s != c)
			s++;
	}
	return (subs);
}

void	free_split(char **res)
{
	int	i;

	if (!res)
		return ;
	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	*extract_substring(const char *s, char c)
{
	const char	*start;
	int			len;
	char		*substring;
	int			i;

	start = s;
	while (*s && *s != c)
		s++;
	len = s - start;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substring[i] = start[i];
		i++;
	}
	substring[len] = '\0';
	return (substring);
}

int	ft_split2(char const *s, char c, char **res)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[i] = extract_substring(s, c);
			if (!res[i])
			{
				free_split(res);
				return (0);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		subs;
	char	**res;

	subs = subcounter(s, c);
	res = (char **)malloc((subs + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (ft_split2(s, c, res))
		res[subs] = (NULL);
	else
		return (NULL);
	return (res);
}
