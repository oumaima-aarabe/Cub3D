/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:53:29 by ichaiq            #+#    #+#             */
/*   Updated: 2023/11/05 16:15:07 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	get_count_line(char *filename)
{
	int	fd;
	int	count;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd))
		count++;
	close(fd);
	return (count);
}

int	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i++]))
			return (0);
	}
	return (1);
}

char	*get_clear_line(int fd)
{
	char	*line;
	char	*clearline;

	line = get_next_line(fd);
	if (!line)
		return (line);
	clearline = ft_strtrim(line, "\n");
	free(line);
	return (clearline);
}
