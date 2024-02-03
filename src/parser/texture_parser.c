/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:01:53 by ichaiq            #+#    #+#             */
/*   Updated: 2023/11/05 22:46:43 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_textures_data	*init_texture_struct(void)
{
	t_textures_data	*data;

	data = ft_calloc(1, sizeof(t_textures_data));
	if (!data)
		return (data);
	data->C_R = 0;
	data->C_G = 0;
	data->C_B = 0;
	data->F_R = 0;
	data->F_G = 0;
	data->F_B = 0;
	data->isCValide = 0;
	data->isFValide = 0;
	data->NO_path = NULL;
	data->SO_path = NULL;
	data->WE_path = NULL;
	data->EA_path = NULL;
	return (data);
}

int	parse_texture_line(char *line, t_textures_data *data)
{
	char	**arr;
	char	*dir;

	arr = ft_split(line, ' ');
	if (!arr)
		return (0);
	if (!arr || !arr[0] || !arr[1] || ft_strlen(arr[0]) > 2)
		return (free_arr(arr), 0);
	dir = arr[0];
	if (!ft_strcmp(dir, "NO") || (ft_strlen(dir) == 1 && dir[0] == 'N' ))
		data->NO_path = ft_strdup(arr[1]);
	if (!ft_strcmp(dir, "SO") || (ft_strlen(dir) == 1 && dir[0] == 'S'))
		data->SO_path = ft_strdup(arr[1]);
	if (!ft_strcmp(dir, "WE") || (ft_strlen(dir) == 1 && dir[0] == 'W'))
		data->WE_path = ft_strdup(arr[1]);
	if (!ft_strcmp(dir, "EA") || (ft_strlen(dir) == 1 && dir[0] == 'E'))
		data->EA_path = ft_strdup(arr[1]);
	free_arr(arr);
	return (1);
}

int	parse_rgb(char *s, char type, t_textures_data *data)
{
	char	**colors;

	colors = ft_split(s, ',');
	if (!colors)
		return (0);
	if (!validate_colors_line(colors) || colors[3])
		return (free_arr(colors), 0);
	if (type == 'F')
	{
		data->F_R = ft_atoi(colors[0]);
		data->F_G = ft_atoi(colors[1]);
		data->F_B = ft_atoi(colors[2]);
		data->isFValide = 1;
		return (free_arr(colors), 1);
	}
	else if (type == 'C')
	{
		data->C_R = ft_atoi(colors[0]);
		data->C_G = ft_atoi(colors[1]);
		data->C_B = ft_atoi(colors[2]);
		data->isCValide = 1;
		return (free_arr(colors), 1);
	}
	return (free_arr(colors), 0);
}

int	parse_color_line(char *line, t_textures_data *data)
{
	char	**arr;

	arr = ft_split(line, ' ');
	if (!arr)
		return (0);
	if (!arr[0] || !arr[1])
		return (free_arr(arr), 0);
	if (!parse_rgb(arr[1], arr[0][0], data))
		return (free_arr(arr), 0);
	return (free_arr(arr), 1);
}

int	get_texture_conf(char *line, t_textures_data *data)
{

	if (parse_texture_line(line, data))
		return (1);
	
	return (0);
}
