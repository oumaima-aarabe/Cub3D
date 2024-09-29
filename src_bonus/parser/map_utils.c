/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:10:18 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 18:34:28 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_index_player(char c)
{
	return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

int	is_char_valide_space(char c)
{
	return (c == '1' || c == '0');
}

int	check_space(char **map, int i, int j)
{
	if (map[i] && map[i][j])
	{
		if ((i > 0 && !is_char_valide_space(map[i - 1][j]))
		|| (map[i + 1] && !is_char_valide_space(map[i + 1][j]))
		|| !map[i + 1])
			return (0);
		else if ((j > 0 && !is_char_valide_space(map[i][j - 1]))
		|| !is_char_valide_space(map[i][j + 1]))
			return (0);
		return (1);
	}
	return (0);
}
