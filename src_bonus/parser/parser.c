/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:42:23 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 22:44:26 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../gameplay/player.h"
#include "../render/render.h"

void	fill_map(char *_line, int fd, t_map_data *data)
{
	char	*line;
	int		i;
	char	*check_line;

	i = 0;
	line = _line;
	while (line)
	{
		check_line = ft_strtrim(line, " t");
		if (!check_line || !ft_strlen(check_line))
			break ;
		data->mini_map[i++] = ft_strdup(line);
		free(line);
		line = get_clear_line(fd);
	}
	data->map_height = i;
}

int	parse_map(int fd, t_data *data, int *r_lines)
{
	char	*line;

	line = get_clear_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		if (!ft_strlen(line))
			free(line);
		else
		{
			if (!allocate_map(*r_lines, data))
				return (0);
			fill_map(line, fd, data->map_data);
			detect_player(data);
			fill_map_space(data->map_data);
			return (1);
		}
		(*r_lines)++;
		line = get_clear_line(fd);
	}
	return (0);
}

int	parse_configuration(int fd, t_data *data, int *r_lines)
{
	char	*line;

	line = get_clear_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		(*r_lines)++;
		if (ft_strlen(line) && ft_strchr("NEWS", line[0])
			&& !get_texture_conf(line, data->tex_data))
			return (free(line), 0);
		else if (ft_strlen(line) && ft_strchr("FC", line[0])
			&& !parse_color_line(line, data->tex_data))
			return (free(line), 0);
		free(line);
		if (is_configuration_valid(data->tex_data))
			break ;
		line = get_clear_line(fd);
	}
	return (is_configuration_valid(data->tex_data));
}

void	detect_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map_data->mini_map[x])
	{
		y = 0;
		while (data->map_data->mini_map[x][y])
		{
			if (is_index_player(data->map_data->mini_map[x][y]))
			{
				set_player_pos(x, y, data->map_data->mini_map[x][y],
					data->map_data->player);
				data->map_data->hasplayer = 1;
				data->map_data->mini_map[x][y] = '0';
			}
			y++;
		}
		x++;
	}
}

int	parse_args(char **av, t_data *data)
{
	int		fd;
	int		r_lines;

	r_lines = 0;
	data->map_filename = av[1];
	data->file_count_lines = get_count_line(data->map_filename);
	fd = open(data->map_filename, O_RDONLY);
	if (fd < 0)
		return (0);
	data->tex_data = init_texture_struct();
	if (!parse_configuration(fd, data, &r_lines)
		|| !parse_map(fd, data, &r_lines) || !validate_map(data))
		return (0);
	data->map_data->map_width = (int)get_longest_line(data->map_data->mini_map);
	return (1);
}
