/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:19:56 by ichaiq            #+#    #+#             */
/*   Updated: 2022/12/07 02:12:59 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*free_ptr(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (ptr);
}

char	*cut_line(char **bak_buffer, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (*bak_buffer)
	{
		while (*(*bak_buffer + i) != '\n' && *(*bak_buffer + i) != '\0')
			i++;
		if (*(*bak_buffer + i) == '\n')
		{
			i++;
			*line = ft_substr(*bak_buffer, 0, i);
			tmp = ft_strdup(*bak_buffer + i);
		}
		else
			*line = ft_strdup(*bak_buffer);
		free_ptr(*bak_buffer);
	}
	else
		free_ptr(*bak_buffer);
	return (tmp);
}

int	read_lines(int fd, char **buffer, char **bak_buffer, char **line)
{
	int		bytes;
	char	*tmp;

	bytes = 1;
	tmp = NULL;
	while (!ft_strchr(*bak_buffer, '\n') && bytes)
	{
		bytes = read(fd, *buffer, BUFFER_SIZE);
		if (bytes)
		{
			(*buffer)[bytes] = '\0';
			tmp = ft_strjoin(*bak_buffer, *buffer);
			free_ptr(*bak_buffer);
			*bak_buffer = tmp;
		}
	}
	free_ptr(*buffer);
	*bak_buffer = cut_line(bak_buffer, line);
	if (!(*line))
		free_ptr(*line);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*bak_buffer;
	char		*buffer;
	char		*line;

	buffer = ft_calloc((int)BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 0)
		return (free_ptr(buffer));
	if (read(fd, buffer, 0) < 0)
		return (free_ptr(bak_buffer), bak_buffer = NULL, free_ptr(buffer));
	if (!bak_buffer)
		bak_buffer = ft_strdup("");
	if (!read_lines(fd, &buffer, &bak_buffer, &line) && !(*line) && buffer)
		return (free_ptr(line), free_ptr(bak_buffer), NULL);
	return (line);
}
