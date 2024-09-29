/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:51:06 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 18:35:10 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	get_wall_offx(t_ray ray, mlx_image_t *tex)
{
	unsigned int	off_x;

	if (ray.dir.horizontal)
	{
		off_x = (ray.f_x / CUBE_FACTOR - (int)(ray.f_x / CUBE_FACTOR))
			* tex->width;
		if (off_x < 0 || off_x > tex->height * tex->height)
			off_x = tex->width + off_x;
	}
	else
		off_x = (ray.f_y / CUBE_FACTOR - (int)(ray.f_y / CUBE_FACTOR))
			* tex->width;
	return (off_x);
}

t_wall_pos	*get_wall_cords(t_ray ray)
{
	t_wall_pos	*cords;

	cords = ft_calloc(1, sizeof(t_wall_pos));
	cords->x = floor(ray.f_x) / CUBE_FACTOR;
	cords->y = floor(ray.f_y) / CUBE_FACTOR;
	cords->wall_x = ray.f_x;
	cords->wall_y = ray.f_y;
	return (cords);
}

int	get_color_pixel(int j, mlx_image_t tex, t_ray ray)
{
	int				c_x;
	int				c_y;
	unsigned int	pos;
	int				color ;

	color = create_trgb(0, 0, 0, 0);
	c_x = get_wall_offx(ray, &tex);
	c_y = j;
	pos = ((c_y * tex.width + c_x) * 4);
	if (pos >= 0 && pos < tex.width * tex.height * 4)
		color = create_trgb(tex.pixels[pos + 0], \
		tex.pixels[pos + 1], tex.pixels[pos + 2], \
		tex.pixels[pos + 3]);
	return (color);
}

mlx_image_t	*get_dir_tex(t_textures_data *tdata, t_direction dir)
{
	if (dir.east)
		return (tdata->east_image);
	if (dir.north)
		return (tdata->north_image);
	if (dir.south)
		return (tdata->south_image);
	if (dir.west)
		return (tdata->west_image);
	return (tdata->west_image);
}
