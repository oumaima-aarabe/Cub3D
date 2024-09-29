/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 23:44:24 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 18:35:05 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

float	normalize(float angle)
{
	if (angle <= -M_PI)
		angle += 2 * M_PI;
	if (angle >= M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

int	wall_ray_collision(float posx, float posy, t_data *data)
{
	int	tmp;
	int	t;

	tmp = (int)(posy / CUBE_FACTOR);
	t = (int)(posx / CUBE_FACTOR);
	if (tmp < 0 || t < 0 || tmp >= data->map_data->map_height \
		|| t >= data->map_data->map_width)
		return (1);
	if (data->map_data->mini_map[tmp][t] == '1')
		return (1);
	return (0);
}

void	init_ray(t_ray *ray)
{
	ray->dir.east = false;
	ray->dir.north = false;
	ray->dir.south = false;
	ray->dir.west = false;
	ray->dir.horizontal = false;
	ray->dir.vertical = false;
}
