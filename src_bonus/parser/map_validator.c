/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 23:17:28 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 18:42:21 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	validate_file_name(char *name, char *extension)
{
	char	**arr;
	int		i;
	int		result;

	i = 0;
	if (!ft_strrchr(name, '.'))
		return (0);
	arr = ft_split(ft_strdup(name), '.');
	while (arr[i])
		i++;
	--i;
	result = !ft_strcmp(arr[i], extension);
	free_arr(arr);
	return (result);
}

int	validate_map_dims(t_map_data *data)
{
	char	*_line;
	char	*line;
	int		h;

	h = 0;
	_line = data->mini_map[h];
	while (_line)
	{
		_line = data->mini_map[h++];
		line = ft_strtrim(_line, " \t\n");
		if (!line || !ft_strlen(line))
			break ;
		else if (!is_valid_line(line))
			return (0);
		if (ft_strlen(line) && \
			(line[0] != '1' || line[ft_strlen(line) - 1] != '1'))
			return (0);
	}
	return (1);
}

int	validate_map_space(char **map)
{
	int	i;
	int	y;

	i = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] == '0')
				if (!check_space(map, i, y))
					return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_data *data)
{
	if (!data->map_data->hasplayer)
		return (0);
	if (!validate_file_name(data->map_filename, "cub"))
		return (0);
	if (!validate_map_dims(data->map_data))
		return (0);
	if (!validate_map_space(data->map_data->mini_map))
		return (0);
	return (1);
}
