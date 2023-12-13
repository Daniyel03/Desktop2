/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dscholz <dscholz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:10:05 by dscholz           #+#    #+#             */
/*   Updated: 2023/10/16 11:10:05 by dscholz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s(char *s)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	if (s[0] != '\0')
	{
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	else
	{
		ft_putstr_fd("", 1);
		return (0);
	}
}