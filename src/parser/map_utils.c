/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:10:18 by ichaiq            #+#    #+#             */
/*   Updated: 2023/12/24 01:51:38 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int is_index_player(char c)
{
    return (c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

void    set_player_onmap(int i, int c, int vert, char *line, t_map_data *data)
{
    (void)line;
    char rot;
    
    rot = data->mini_map[i][c / CUBE_FACTOR];
    if ((c % CUBE_FACTOR) == CUBE_FACTOR / 2 
        && (vert % CUBE_FACTOR) == (CUBE_FACTOR / 2))
    {
        line[c] = data->mini_map[i][c / CUBE_FACTOR];
        set_player_pos(c, vert + (CUBE_FACTOR * i), rot, data->player);
    }
    else 
        line[c] = '0';
}