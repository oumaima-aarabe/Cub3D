/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:58:00 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 22:45:21 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../gameplay/player.h"
#include "../utils/utils.h"

void	render_f(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT / 2)
		{
			mlx_put_pixel(data->window_image, i, j++,
				create_trgb(data->tex_data->c_r, data->tex_data->c_g,
					data->tex_data->c_b, 255));
		}
		i++;
	}
}

void	render_c(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = HEIGHT / 2;
		while (j < HEIGHT)
		{
			mlx_put_pixel(data->window_image, i, j++,
				create_trgb(data->tex_data->f_r, data->tex_data->f_g,
					data->tex_data->f_b, 255));
		}
		i++;
	}
}

void	render_fc(t_data *data)
{
	render_f(data);
	render_c(data);
}

int	keyfunc(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_player(cos(data->map_data->player->rot_angle) * 8,
			sin(data->map_data->player->rot_angle) * 8, data->map_data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_player(-cos(data->map_data->player->rot_angle) * 8,
			-sin(data->map_data->player->rot_angle) * 8, data->map_data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_player(cos(data->map_data->player->rot_angle - M_PI_2) * 8, \
	sin(data->map_data->player->rot_angle - M_PI_2) * 8, data->map_data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_player(cos(data->map_data->player->rot_angle + M_PI_2) * 8, \
	sin(data->map_data->player->rot_angle + M_PI_2) * 2 * 8, data->map_data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q)
		|| mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->map_data->player->rot_angle -= (2 * M_PI) / 180;
	if (mlx_is_key_down(data->mlx, MLX_KEY_E)
		|| mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->map_data->player->rot_angle += (2 * M_PI) / 180;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		return (0);
	data->map_data->player->rot_angle = \
		normalize(data->map_data->player->rot_angle);
	return (1);
}

void	render_world(void *Data)
{
	t_data	*data;

	data = (t_data *)Data;
	if (!keyfunc(data))
		clean_exit(data);
	render_fc(data);
	render(data);
}
