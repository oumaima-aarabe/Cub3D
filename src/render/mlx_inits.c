/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_inits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:29:59 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 23:57:44 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../parser/parser.h"
#include "../utils/utils.h"

int	init_mlx_world(t_data *data)
{
	data->window_image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->window_image, 0, 0);
	return (1);
}

int	init_mlx_data(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!data->mlx)
		return (0);
	if (!load_textures(data))
		return (0);
	data->window_image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->window_image, 0, 0);
	return (1);
}

void	handle_mlx_close(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	clean_exit(data);
}

int	render_window(t_data *data)
{
	if (!init_mlx_data(data))
		return (0);
	init_mlx_world(data);
	mlx_loop_hook(data->mlx, render_world, data);
	mlx_close_hook(data->mlx, handle_mlx_close, (void *)data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (1);
}
