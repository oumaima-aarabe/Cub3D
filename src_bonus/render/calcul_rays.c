/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:54:57 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 18:34:49 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	calcul_v_right(t_data *data, t_ray *ray, t_inters *A)
{
	float	adj;
	float	opp;

	A->p_x = floor(data->map_data->player->current_pos->x / CUBE_FACTOR)
		* CUBE_FACTOR + CUBE_FACTOR;
	adj = A->p_x - data->map_data->player->current_pos->x;
	opp = fabs(adj * tan(ray->ray_ang));
	if (ray->ray_ang <= 0 && ray->ray_ang > -M_PI_2)
	{
		A->p_y = data->map_data->player->current_pos->y - opp;
		while (wall_ray_collision(A->p_x, A->p_y, data) == 0)
		{
			A->p_x += 64;
			A->p_y -= fabs(64 * tan(ray->ray_ang));
		}
	}
	else
	{
		A->p_y = data->map_data->player->current_pos->y + opp;
		while (wall_ray_collision(A->p_x, A->p_y, data) == 0)
		{
			A->p_x += 64;
			A->p_y += 64 * tan(ray->ray_ang);
		}
	}
}

void	calcul_v_left(t_data *data, t_ray *ray, t_inters *A)
{
	float	adj;
	float	opp;

	A->p_x = floor(data->map_data->player->current_pos->x / 64) * 64;
	adj = data->map_data->player->current_pos->x - A->p_x;
	opp = fabs(adj * tan(ray->ray_ang));
	if (ray->ray_ang >= -M_PI && ray->ray_ang <= -M_PI_2)
	{
		A->p_y = data->map_data->player->current_pos->y - opp;
		while (wall_ray_collision(A->p_x - 1, A->p_y, data) == 0)
		{
			A->p_x -= 64;
			A->p_y -= fabs(64 * tan(ray->ray_ang));
		}
	}
	else
	{
		A->p_y = data->map_data->player->current_pos->y + opp;
		while (wall_ray_collision(A->p_x - 1, A->p_y, data) == 0)
		{
			A->p_x -= 64;
			A->p_y += fabs(64 * tan(ray->ray_ang));
		}
	}
}

void	calcul_h_up(t_data *data, t_ray *ray, t_inters *A)
{
	float	adj;
	float	opp;

	A->p_y = floor(data->map_data->player->current_pos->y / 64) * 64;
	adj = data->map_data->player->current_pos->y - A->p_y;
	opp = fabs(adj / tan(ray->ray_ang));
	if (ray->ray_ang <= 0 && ray->ray_ang >= -M_PI_2)
	{
		A->p_x = data->map_data->player->current_pos->x + opp;
		while (wall_ray_collision(A->p_x, A->p_y - 1, data) == 0)
		{
			A->p_x += fabs(64 / tan(ray->ray_ang));
			A->p_y -= 64;
		}
	}
	else
	{
		A->p_x = data->map_data->player->current_pos->x - opp;
		while (wall_ray_collision(A->p_x, A->p_y - 1, data) == 0)
		{
			A->p_x -= fabs(64 / tan(ray->ray_ang));
			A->p_y -= 64;
		}
	}
}

void	calcul_h_down(t_data *data, t_ray *ray, t_inters *A)
{
	float	adj;
	float	opp;

	A->p_y = floor(data->map_data->player->current_pos->y / 64) * 64 + 64;
	adj = A->p_y - data->map_data->player->current_pos->y;
	opp = fabs(adj / tan(ray->ray_ang));
	if (ray->ray_ang >= 0 && ray->ray_ang <= M_PI_2)
	{
		A->p_x = data->map_data->player->current_pos->x + opp;
		while (wall_ray_collision(A->p_x, A->p_y + 1, data) == 0)
		{
			A->p_x += fabs(64 / tan(ray->ray_ang));
			A->p_y += 64;
		}
	}
	else
	{
		A->p_x = data->map_data->player->current_pos->x - opp;
		while (wall_ray_collision(A->p_x, A->p_y, data) == 0)
		{
			A->p_y += 64;
			A->p_x -= fabs(64 / tan(ray->ray_ang));
		}
	}
}
