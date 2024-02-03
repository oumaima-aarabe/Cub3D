/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:19:59 by ichaiq            #+#    #+#             */
/*   Updated: 2023/07/17 17:25:15 by ahallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_count_words(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != '\0')
		{
			count++;
			i++;
		}
		while (s[i] == c)
			i++;
		i++;
	}
	return (count);
}

static int	get_len(char *l, const char *s)
{
	int	len;

	if (l != NULL)
		len = (void *)l - (void *)s;
	else
		len = ft_strlen(s);
	return (len);
}

static char	**fill_array(const char *s, char c, char **arr, int countw)
{
	char	*l;
	int		len;
	int		x;
	char	*str;

	x = 0;
	while (x < countw)
	{
		while (!ft_strncmp(s, &c, 1))
			s++;
		l = ft_strchr(s, c);
		len = get_len(l, s);
		str = ft_substr(s, 0, len);
		if (!str)
		{
			while (x-- > 0)
				ft_free(arr[x]);
			return (NULL);
		}
		arr[x] = str;
		s += len + 1;
		x++;
	}
	arr[x] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		count_words;
	char	*str;
	char	**arr;

	if (!s)
		return (NULL);
	str = ft_strtrim(s, " ");
	if (!str)
		return (NULL);
	count_words = get_count_words(str, c);
	arr = ft_calloc(sizeof(char *), (count_words + 1));
	if (!arr)
		return (NULL);
	arr = fill_array(str, c, arr, count_words);
	ft_free(str);
	if (!arr)
		return (NULL);
	return (arr);
}
