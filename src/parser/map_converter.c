/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:44:17 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/05 00:59:55 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// int fill_dims_cube(char **arr, int *i, int *x, t_map_data *data)
// {
// 	(void)x;
// 	int c;
// 	int y;

// 	c = *i * CUBE_FACTOR;
// 	y = 0;
// 	if (data->mini_map && data->mini_map[*i])
// 	{
// 		arr[c * CUBE_FACTOR] = ft_calloc((data->map_width + 2) * CUBE_FACTOR, sizeof(char)); 
// 		while (y < (data->map_width + 1) * CUBE_FACTOR)
// 		{
// 			printf("y : %d | fy : %d\n", y , y%CUBE_FACTOR);
// 			arr[c * CUBE_FACTOR][y] = data->mini_map[*i][y / CUBE_FACTOR];
// 			y++;	
// 		}
// 		printf("line filled : %s\n", arr[c * CUBE_FACTOR]);
// 		// if (!data->mini_map[c])
// 		// 	c = 0;
// 	}
// 	return (1);
// }


void copy_line(char *src, char *dst)
{
	while (src && *src)
		*dst++ = *src++;
}

void fill_map_space(t_map_data *data)
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
