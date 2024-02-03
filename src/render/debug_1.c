/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:54:57 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/08 16:15:02 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "render.h"

size_t get_longest_line(char **line)
{
	size_t max;
	int i;
	
	i = 0;
	max = 0;
	while (line[i])
		if (ft_strlen(line[i++]) > max)
			max = ft_strlen(line[i - 1]);
	// printf("longuest line : %zu\n", max);
	return (max);
	
}


int draw_2d_map(t_data *data)
{
	int x = 0;
	int y = 0;
	data->map_image = mlx_new_image(data->mlx, WIDTH, HEIGHT / 2);
	mlx_image_to_window(data->mlx, data->map_image, 0, 0);
	// printf("player pos x : %f\n", data->map_data->player->current_pos->x);
	// printf("player pos y : %f\n", data->map_data->player->current_pos->y);
	while (data->map_data->mini_map[x])
	{
		y = 0;
		while (data->map_data->mini_map[x][y])
		{
			draw_block(x, y, data);
			y++;
		}
		x++;
	}
	draw_player(data);
	return (0);
}
double	dtor(double degree)
{
	return (degree * (M_PI / 180));
}

double normalize1(double x)
{
	if (x >= 2 * M_PI)
		return (x - (2 * M_PI));
	else if (x < 0)
		return (x + (2 * M_PI));
	else
		return (x);
}

void keyfunc(void *Data)
{
	t_data *data = (t_data *)Data;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_player(cos(data->map_data->player->rot_angle) * 2,
			sin(data->map_data->player->rot_angle) * 2, data->map_data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_player(-cos(data->map_data->player->rot_angle) * 2,
			-sin(data->map_data->player->rot_angle) * 2, data->map_data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_player(cos(data->map_data->player->rot_angle - M_PI_2) * 0.2 ,
				sin(data->map_data->player->rot_angle - M_PI_2) * 0.2, data->map_data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_player(cos(data->map_data->player->rot_angle + M_PI_2) * 0.2,
				sin(data->map_data->player->rot_angle + M_PI_2) * 0.2, data->map_data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q))
		data->map_data->player->rot_angle -= (0.2 * M_PI_2) / 90;
	if (mlx_is_key_down(data->mlx, MLX_KEY_E))
		data->map_data->player->rot_angle += (0.2 * M_PI_2) / 90;
	data->map_data->player->rot_angle = normalize1(data->map_data->player->rot_angle );

}

void	f_5(void *Data)
{
	t_data *data = (t_data *)Data;
	
	// keyfunc(data);
	render_fc(data);
	render(data);
}


int render_debug_window(t_data *data)
{
	int width;
	int height;

	puts("looping mlx\n");
	width =  data->map_data->map_width * CUBE_FACTOR;
	height = data->map_data->map_height * CUBE_FACTOR;

	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!load_textures(data))
		return(mlx_terminate(data->mlx),
			ft_putstr_fd("Error: Failed on loading textures", STDERR_FILENO), 0);
	data->map_image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->map_image, 0, 0);
	// draw_2d_map(data);
	mlx_loop_hook(data->mlx, f_5, data);
	mlx_loop_hook(data->mlx, keyfunc, data);
	// mlx_loop_hook(data->mlx, draw_2d_map, data);
    // mlx_key_hook(data->mlx_window, key_hooks, data );
	// mlx_key_hook(data->mlx, keyfunc, data);

	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	
	return (0);
}