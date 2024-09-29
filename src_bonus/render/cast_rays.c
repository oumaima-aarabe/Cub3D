/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:37:35 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 21:23:10 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	cast_hsingle_ray(t_data *data, t_ray *ray)
{
	t_inters	inter;

	ray->ray_ang = normalize(ray->ray_ang);
	if (ray->ray_ang <= 0 && ray->ray_ang >= -M_PI)
		calcul_h_up(data, ray, &inter);
	else
		calcul_h_down(data, ray, &inter);
	ray->distance_h = sqrt(
			pow((inter.p_x - data->map_data->player->current_pos->x), 2)
			+ pow((inter.p_y - data->map_data->player->current_pos->y), 2));
	ray->x_col_h = inter.p_x;
	ray->y_col_h = inter.p_y;
}

void	cast_vsingle_ray(t_data *data, t_ray *ray)
{
	t_inters	inter;

	ray->ray_ang = normalize(ray->ray_ang);
	if (ray->ray_ang > -M_PI_2 && ray->ray_ang <= M_PI_2)
		calcul_v_right(data, ray, &inter);
	else
		calcul_v_left(data, ray, &inter);
	ray->distance_v = sqrt(
			pow(inter.p_x - data->map_data->player->current_pos->x, 2)
			+ pow(inter.p_y - data->map_data->player->current_pos->y, 2));
	ray->x_col_v = inter.p_x;
	ray->y_col_v = inter.p_y;
}

void	fill_dir(t_ray *ray)
{
	if (ray->flag == 1)
	{
		ray->dir.vertical = true;
		ray->dir.horizontal = false;
		ray->f_d = ray->distance_v;
		ray->f_x = ray->x_col_v;
		ray->f_y = ray->y_col_v;
		if (ray->ray_ang > -M_PI_2 && ray->ray_ang < M_PI_2)
			ray->dir.east = true;
		ray->dir.west = !ray->dir.east;
	}
	else
	{
		ray->dir.horizontal = true;
		ray->dir.vertical = false;
		ray->f_d = ray->distance_h;
		ray->f_x = ray->x_col_h;
		ray->f_y = ray->y_col_h;
		if (ray->ray_ang < 0 && ray->ray_ang > -M_PI)
			ray->dir.south = true;
		ray->dir.north = !ray->dir.south;
	}
}

void	cast_ray(t_data *data, t_ray *ray)
{
	init_ray(ray);
	ray->distance_h = LONG_MAX;
	ray->distance_v = LONG_MAX;
	cast_vsingle_ray(data, ray);
	cast_hsingle_ray(data, ray);
	if (ray->distance_h > ray->distance_v)
		ray->flag = 1;
	else
		ray->flag = 2;
	fill_dir(ray);
}
