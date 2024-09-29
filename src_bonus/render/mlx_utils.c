/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:48:52 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 18:35:01 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	create_trgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

size_t	get_longest_line(char **line)
{
	size_t	max;
	int		i;

	i = 0;
	max = 0;
	while (line[i])
		if (ft_strlen(line[i++]) > max)
			max = ft_strlen(line[i - 1]);
	return (max);
}

double	dtor(double degree)
{
	return (degree * (M_PI / 180));
}
