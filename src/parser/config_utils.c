/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 11:16:53 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/01 21:49:33 by ichaiq           ###   ########.fr       */
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
	data->map_data->hasPlayer = 0;
	arr = ft_calloc(data->map_data->map_height + 1, sizeof(char *));
	data->map_data->mini_map = arr;
	return (1);
}

int	is_configuration_valid(t_textures_data *data)
{
	return (data->EA_path && data->NO_path && data->SO_path
		&& data->WE_path && data->isCValide && data->isFValide);
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

mlx_texture_t *open_texture(char *path)
{	
	int	fd;

	// printf("path : %s\n", path);
	if (!validate_file_name(path, "png"))
		return (/*ft_putstr_fd("File must be a .png", STDERR_FILENO),*/ NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);	
	close(fd);
	return (mlx_load_png(path));
}

int load_textures(t_data *gData)
{
	t_textures_data *data;
	data = gData->tex_data;
	if (data->EA_path && data->NO_path && data->SO_path
		&& data->WE_path){
		data->EA_texture = open_texture(data->EA_path);
		data->NO_texture = open_texture(data->NO_path);
		data->SO_texture = open_texture(data->SO_path);
		data->WE_texture = open_texture(data->WE_path);
	
	}
	else
		return (0);
	if (data->EA_texture && data->NO_texture && data->SO_texture && data->WE_texture)
	{
		data->EA_image = mlx_texture_to_image(gData->mlx ,data->EA_texture);
		data->NO_image = mlx_texture_to_image(gData->mlx ,data->NO_texture);
		data->SO_image = mlx_texture_to_image(gData->mlx ,data->SO_texture);
		data->WE_image = mlx_texture_to_image(gData->mlx ,data->WE_texture);
	}
	else
		return ( ft_putstr_fd("Texture should be a .png image\n", STDERR_FILENO), 0);
	
	return (data->EA_image && data->NO_image
		&& data->SO_image && data->WE_image);
}