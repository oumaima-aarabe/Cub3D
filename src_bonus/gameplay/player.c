/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:46 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 21:24:19 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_pos	*set_player_pos(int x, int y, char rot, t_player *data)
{
	t_pos	*position;

	if (!data->current_pos)
	{
		position = ft_calloc(1, sizeof(t_pos));
		if (!position)
			return (position);
		data->current_pos = position;
	}
	data->current_pos->x = (y * CUBE_FACTOR) + (CUBE_FACTOR / 2);
	data->current_pos->y = (x * CUBE_FACTOR) + (CUBE_FACTOR / 2);
	if (rot == 'N')
		data->rot_angle = M_PI_2;
	else if (rot == 'S')
		data->rot_angle = -M_PI_2;
	else if (rot == 'E')
		data->rot_angle = 0.0;
	else if (rot == 'W')
		data->rot_angle = -M_PI;
	return (data->current_pos);
}

t_pos	*move_player(float x, float y, t_map_data *data)
{
	int	raw_x;
	int	raw_y;
	int	cx;
	int	cy;

	cx = (int)((data->player->current_pos->x) / CUBE_FACTOR);
	cy = (int)((data->player->current_pos->y) / CUBE_FACTOR);
	raw_x = (int)((data->player->current_pos->x + (2 * x)) / CUBE_FACTOR);
	raw_y = (int)((data->player->current_pos->y + (2 * y)) / CUBE_FACTOR);
	if (data->mini_map[cy][raw_x] == '1' || data->mini_map[raw_y][cx] == '1'
	|| data->mini_map[raw_y][raw_x] == '1')
		return (data->player->current_pos);
	data->player->current_pos->x += x;
	data->player->current_pos->y += y;
	return (data->player->current_pos);
}
