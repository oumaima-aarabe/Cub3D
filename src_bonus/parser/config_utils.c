/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:16:53 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 18:41:58 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	allocate_map(int r_count, t_data *data)
{
	char	**arr;

	data->map_data = ft_calloc(1, sizeof(t_map_data));
	if (!data->map_data)
		return (0);
	data->map_data->player = ft_calloc(1, sizeof(t_player));
	if (!data->map_data->player)
		return (0);
	data->map_data->player->current_pos = NULL;
	data->map_data->player->start_pos = NULL;
	data->map_data->map_height = data->file_count_lines - r_count;
	data->map_data->hasplayer = 0;
	arr = ft_calloc(data->map_data->map_height + 1, sizeof(char *));
	data->map_data->mini_map = arr;
	return (1);
}

int	is_configuration_valid(t_textures_data *data)
{
	return (data->east_path && data->north_path && data->south_path
		&& data->west_path && data->isc_valide && data->isf_valide);
}

int	validate_colors_line(char **arr)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!arr[i] || (i > 0 && !ft_isnumber(arr[i])))
			return (0);
		i++;
	}
	return (i);
}

mlx_texture_t	*open_texture(char *path)
{
	int	fd;

	if (!validate_file_name(path, "png"))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (mlx_load_png(path));
}

int	load_textures(t_data *gData)
{
	t_textures_data	*data;

	data = gData->tex_data;
	if (!data->east_path || !data->north_path || !data->south_path
		|| !data->west_path)
		return (0);
	data->east_texture = open_texture(data->east_path);
	data->north_texture = open_texture(data->north_path);
	data->south_texture = open_texture(data->south_path);
	data->west_texture = open_texture(data->west_path);
	if (!data->east_texture || !data->north_texture
		|| !data->south_texture || !data->west_texture)
		return (0);
	data->east_image = mlx_texture_to_image(gData->mlx, data->east_texture);
	data->north_image = mlx_texture_to_image(gData->mlx, data->north_texture);
	data->south_image = mlx_texture_to_image(gData->mlx, data->south_texture);
	data->west_image = mlx_texture_to_image(gData->mlx, data->west_texture);
	return (data->east_image && data->north_image
		&& data->south_image && data->west_image);
}
