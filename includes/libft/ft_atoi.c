/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:19:59 by ichaiq            #+#    #+#             */
/*   Updated: 2022/10/22 10:20:36 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == ' '
		|| c == '\v' || c == '\f' || c == '\r');
}

static char	*l_trim(char *str)
{
	while (is_space(*str) && *str != '\0')
	{
		str++;
	}
	return (str);
}

static int	get_signe(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

static long	get_nbr(char*str)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + ((int)str[i] - 48);
		i++;
	}
	return (nbr);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	char	*_str;

	i = 0;
	signe = 1;
	_str = l_trim((char *)str);
	if (_str[i] != '\0' && get_signe(_str[i]) != 0)
	{
		signe *= get_signe(_str[i]);
		i++;
	}
	return (signe * get_nbr(_str + i));
}
