/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:44:17 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 22:43:06 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../render/render.h"

void	copy_line(char *src, char *dst)
{
	while (src && *src)
		*dst++ = *src++;
}

void	fill_map_space(t_map_data *data)
{
	char	**map;
	int		max;
	int		c;
	char	*tmp;
	char	*new;

	c = 0;
	map = data->mini_map;
	max = get_longest_line(map);
	while (map[c])
	{
		tmp = map[c];
		new = ft_calloc(max + 1, sizeof(char));
		ft_memset(new, ' ', max);
		copy_line(tmp, new);
		free(tmp);
		map[c++] = new;
	}
}
