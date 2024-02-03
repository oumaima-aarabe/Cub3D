/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:19:59 by ichaiq            #+#    #+#             */
/*   Updated: 2022/10/22 10:20:36 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	fill_nbr(char *str, int *n, int *signe, int *l)
{
	int	nbr;
	int	len;

	nbr = *n;
	len = *l;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			str[len] = '8';
			nbr = nbr / 10;
		}
		*signe = -1;
		nbr = nbr * -1;
		len++;
	}
	while (nbr % 10 != nbr)
	{
		str[len++] = (char)((nbr % 10) + 48);
		nbr = nbr / 10;
	}
	str[len++] = nbr + 48;
	*n = nbr;
	*l = len;
}

static int	get_count_digit(int n)
{
	int	nbr;
	int	count;

	nbr = n;
	count = 2;
	if (nbr <= 0)
	{
		if (nbr == INT_MIN)
			nbr += 1;
		nbr *= -1;
		count++;
	}
	if (!nbr)
		return (3);
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count + 1);
}

void	ft_rev_char_tab(char *tab, int size)
{
	int		i;
	int		y;
	char	tmp;

	i = size - 1;
	y = 0;
	while (i >= 0 && y < i)
	{
		tmp = tab[i];
		tab[i] = tab[y];
		tab[y] = tmp;
		y++;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		nbr;
	int		len;
	char	*str;
	char	*a;
	int		signe;

	str = ft_calloc(get_count_digit(n), sizeof(char));
	if (!str)
		return (NULL);
	nbr = n;
	len = 0;
	signe = 1;
	fill_nbr(str, &nbr, &signe, &len);
	if (signe == -1)
		str[len++] = '-';
	str[len] = '\0';
	ft_rev_char_tab(str, len);
	a = ft_strdup(str);
	ft_free(str);
	return (a);
}
