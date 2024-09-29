/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:22:12 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 23:07:22 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

double	intercept_th(t_ray ray, t_data *data)
{
	double	a;
	double	b;
	double	c;

	a = ray.f_d * cos(ray.ray_ang - data->map_data->player->rot_angle);
	b = (WIDTH / 2) / tan(dtor(FOV / 2));
	c = (double)CUBE_FACTOR;
	return ((c / a) * b);
}

void	draw_wall_texture(mlx_image_t *tex, t_ray ray,
		t_data *data, t_ray_wall wall)
{
	int	hold;
	int	tmp;
	int	j;
	int	offset;

	j = wall.wrg.i;
	while (j < wall.wrg.j)
	{
		hold = 0;
		if (wall.wall_h > HEIGHT)
			hold = (wall.wall_h - HEIGHT) / 2;
		tmp = j - wall.wrg.i;
		offset = (tmp * tex->height / wall.wall_h)
			+ (hold * tex->height / wall.wall_h);
		mlx_put_pixel(data->window_image, wall.col, j,
			get_color_pixel(offset, *tex, ray));
		j++;
	}
}

void	draw_ray(int i, t_data *data, t_ray ray)
{
	t_ray_wall	wall;
	double		wall_h;
	double		h_value;
	mlx_image_t	*tex;

	tex = get_dir_tex(data->tex_data, ray.dir);
	wall.wall_h = intercept_th(ray, data);
	wall.col = i;
	wall_h = wall.wall_h;
	h_value = wall_h;
	if (wall_h > HEIGHT)
		wall_h = HEIGHT;
	wall.wrg.i = (HEIGHT / 2) - (wall_h / 2);
	wall.wrg.j = (HEIGHT / 2) + (wall_h / 2);
	draw_wall_texture(tex, ray, data, wall);
}

void	render(t_data *data)
{
	t_ray	ray;
	int		i;

	i = -1;
	ray.ray_ang = normalize(data->map_data->player->rot_angle
			- (dtor(FOV / 2)));
	while (++i < WIDTH)
	{
		cast_ray(data, &ray);
		draw_ray(i, data, ray);
		ray.ray_ang = normalize(ray.ray_ang + (dtor(FOV) / WIDTH));
	}
	draw_2d_map(data);
}
