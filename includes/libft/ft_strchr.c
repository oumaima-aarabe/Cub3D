/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:19:59 by ichaiq            #+#    #+#             */
/*   Updated: 2022/10/22 10:20:36 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	*adress;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (c % 256))
		{
			adress = (unsigned char *)&s[i];
			return ((char *)(adress));
		}
		i++;
	}
	if (s[i] == (c % 256))
		return ((char *) &s[i]);
	return ((char *) '\0');
}
