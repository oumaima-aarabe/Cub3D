/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:01:53 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 18:34:37 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_textures_data	*init_texture_struct(void)
{
	t_textures_data	*data;

	data = ft_calloc(1, sizeof(t_textures_data));
	if (!data)
		return (data);
	data->c_r = 0;
	data->c_g = 0;
	data->c_b = 0;
	data->f_r = 0;
	data->f_g = 0;
	data->f_b = 0;
	data->isc_valide = 0;
	data->isf_valide = 0;
	data->north_path = NULL;
	data->south_path = NULL;
	data->west_path = NULL;
	data->east_path = NULL;
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
		data->north_path = ft_strdup(arr[1]);
	if (!ft_strcmp(dir, "SO") || (ft_strlen(dir) == 1 && dir[0] == 'S'))
		data->south_path = ft_strdup(arr[1]);
	if (!ft_strcmp(dir, "WE") || (ft_strlen(dir) == 1 && dir[0] == 'W'))
		data->west_path = ft_strdup(arr[1]);
	if (!ft_strcmp(dir, "EA") || (ft_strlen(dir) == 1 && dir[0] == 'E'))
		data->east_path = ft_strdup(arr[1]);
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
		data->f_r = ft_atoi(colors[0]);
		data->f_g = ft_atoi(colors[1]);
		data->f_b = ft_atoi(colors[2]);
		data->isf_valide = 1;
		return (free_arr(colors), 1);
	}
	else if (type == 'C')
	{
		data->c_r = ft_atoi(colors[0]);
		data->c_g = ft_atoi(colors[1]);
		data->c_b = ft_atoi(colors[2]);
		data->isc_valide = 1;
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
	if ((!ft_strcmp(arr[0], "F") || !ft_strcmp(arr[0], "C"))
		&& !parse_rgb(arr[1], arr[0][0], data))
		return (free_arr(arr), 0);
	return (free_arr(arr), 1);
}

int	get_texture_conf(char *line, t_textures_data *data)
{
	if (parse_texture_line(line, data))
		return (1);
	return (0);
}
