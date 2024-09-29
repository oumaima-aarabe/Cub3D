/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:06:57 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 19:09:58 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_mlx_textures(t_data *data)
{
	if (!data->tex_data)
		return ;
	if (data->tex_data->north_texture)
		mlx_delete_texture(data->tex_data->north_texture);
	if (data->tex_data->south_texture)
		mlx_delete_texture(data->tex_data->south_texture);
	if (data->tex_data->west_texture)
		mlx_delete_texture(data->tex_data->west_texture);
	if (data->tex_data->east_texture)
		mlx_delete_texture(data->tex_data->east_texture);
}

void	free_images_data(t_data *data)
{
	if (!data->tex_data)
		return ;
	if (data->tex_data->north_image)
		mlx_delete_image(data->mlx, data->tex_data->north_image);
	if (data->tex_data->south_image)
		mlx_delete_image(data->mlx, data->tex_data->south_image);
	if (data->tex_data->west_image)
		mlx_delete_image(data->mlx, data->tex_data->west_image);
	if (data->tex_data->east_image)
		mlx_delete_image(data->mlx, data->tex_data->east_image);
}

void	free_tex_data(t_data *data)
{
	if (data->tex_data)
	{
		free_mlx_textures(data);
		free_images_data(data);
		if (data->tex_data->north_path)
			ft_free(data->tex_data->north_path);
		if (data->tex_data->south_image)
			ft_free(data->tex_data->south_path);
		if (data->tex_data->west_path)
			ft_free(data->tex_data->west_path);
		if (data->tex_data->east_path)
			ft_free(data->tex_data->east_path);
		ft_free(data->tex_data);
		data->tex_data = NULL;
	}
}

void	free_map_data(t_data *data)
{
	if (!data->map_data)
		return ;
	if (data->map_data->player)
	{
		if (data->map_data->player->current_pos)
			ft_free(data->map_data->player->current_pos);
		if (data->map_data->player->start_pos)
			ft_free(data->map_data->player->start_pos);
	}
	if (data->map_data->mini_map)
		free_arr(data->map_data->mini_map);
}

void	clean_exit(t_data *data)
{
	free_tex_data(data);
	free_map_data(data);
	if (data->mlx)
		mlx_terminate(data->mlx);
	ft_free(data);
	exit(0);
}
