/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:19:59 by ichaiq            #+#    #+#             */
/*   Updated: 2022/10/22 10:20:36 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		n;
	char		*str;
	char		*to_find;

	str = (char *)haystack;
	to_find = (char *)needle;
	n = ft_strlen(to_find);
	if (*to_find == '\0' || to_find == 0)
		return (str);
	if (!len)
		return ((char *) len);
	while (*str != '\0' && len > 0)
	{
		if (ft_strncmp(str, to_find, n) == 0 && len >= n)
		{
			return (str);
		}
		str++;
		len--;
	}
	return (NULL);
}
