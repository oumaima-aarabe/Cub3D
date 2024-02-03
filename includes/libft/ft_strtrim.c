/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:19:59 by ichaiq            #+#    #+#             */
/*   Updated: 2022/10/22 10:20:36 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_start(const char *s1, const char *set)
{
	int	i;
	int	len;

	len = ft_strlen(s1);
	i = 0;
	while (i < len - 1)
	{
		if (ft_strchr(set, (int)(s1[i])) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	get_end(const char *s1, const char *set)
{
	int	i;
	int	len;

	len = ft_strlen(s1);
	i = len - 1;
	while (i >= 0)
	{
		if (ft_strchr(set, (int)(s1[i])) == 0)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	len = end - start +1 ;
	if (start > end)
		return (ft_strdup(""));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, len + 1);
	return (str);
}
