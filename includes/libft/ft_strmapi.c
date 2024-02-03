/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:19:59 by ichaiq            #+#    #+#             */
/*   Updated: 2022/10/22 10:20:36 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	new_str = ft_strdup(s);
	if (!new_str)
		return (NULL);
	while (new_str[i])
	{
		new_str[i] = (*f)(i, new_str[i]);
		i++;
	}
	return (new_str);
}
