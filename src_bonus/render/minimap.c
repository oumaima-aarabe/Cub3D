/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:05:55 by ouaarabe          #+#    #+#             */
/*   Updated: 2024/01/13 23:53:37 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "render.h"

void	put_p(t_mini m, t_data *data)
{
	if (m.grid_x >= 0 && m.grid_y >= 0
		&& m.grid_y < data->map_data->map_height
		&& m.grid_x < data->map_data->map_width)
	{
		if (data->map_data->mini_map[m.grid_y][m.grid_x] == '1')
			mlx_put_pixel(data->window_image, m.beg_x,
				m.beg_y, create_trgb(0, 0, 255, 255));
		else if (data->map_data->mini_map[m.grid_y][m.grid_x] == '0')
			mlx_put_pixel(data->window_image,
				m.beg_x, m.beg_y, create_trgb(0, 0, 0, 255));
	}
}

void	draw_player_on_2d(t_data *data)
{
	int		j;
	int		i;
	double	distance;

	j = 145;
	while (j < 155)
	{
		i = 145;
		while (i < 155)
		{
			distance = sqrt(pow(i - 150, 2) + pow(j - 150, 2));
			if (distance <= 10)
				mlx_put_pixel(data->window_image, i, j,
					create_trgb(255, 0, 0, 255));
			i++;
		}
		j++;
	}
}

void	draw_2d_map(t_data *data)
{
	t_mini	m;

	m.beg_y = 0;
	m.py = data->map_data->player->current_pos->y - 150;
	while (m.beg_y < 300)
	{
		m.grid_y = (int)floor(m.py / CUBE_FACTOR);
		m.beg_x = 0;
		m.px = data->map_data->player->current_pos->x - 150;
		while (m.beg_x < 300)
		{
			m.grid_x = (int)(m.px / CUBE_FACTOR);
			put_p(m, data);
			m.beg_x++;
			m.px++;
		}
		m.beg_y++;
		m.py++;
	}
	draw_player_on_2d(data);
}
