/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:19:59 by ichaiq            #+#    #+#             */
/*   Updated: 2022/10/22 10:20:36 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*first_src;
	size_t		i;

	if (dstsize + 1 == 0)
		dstsize = ft_strlen(src) + 1;
	i = dstsize;
	first_src = src;
	while (i != 0 && --i != 0)
	{
		if (*src != '\0')
			*dst++ = *src++;
	}
	if (i == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - first_src - 1);
}
