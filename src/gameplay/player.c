/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:46 by ichaiq            #+#    #+#             */
/*   Updated: 2023/12/24 02:00:32 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

t_pos   *set_player_pos(int x, int y, char rot, t_player * data)
{
    t_pos *position;

    if (!data->current_pos)
    {
        position = ft_calloc(1, sizeof(t_pos));
        if (!position)
            return position;
        data->current_pos = position;
    }
    data->current_pos->x = (y * CUBE_FACTOR ) + (CUBE_FACTOR / 2);
    data->current_pos->y = (x * CUBE_FACTOR ) + (CUBE_FACTOR / 2);
    if (rot == 'N')
        data->rot_angle = 3 * M_PI_2;
    else if (rot == 'S')
        data->rot_angle = M_PI_2;
    else if (rot == 'E')
        data->rot_angle = 0.0;
    else if (rot == 'W')
        data->rot_angle = 2 * M_PI_2;
    return (data->current_pos);
}


t_pos *move_player(float x, float y, t_map_data *data)
{
    int rawX;
    int rawY;

    rawX = (int)((data->player->current_pos->x + x) / CUBE_FACTOR);
    rawY = (int)((data->player->current_pos->y + y) / CUBE_FACTOR);

    if (data->mini_map[rawY][rawX] == '1')
        return (data->player->current_pos);

    data->player->current_pos->x += x;
    data->player->current_pos->y += y;
    return (data->player->current_pos);
}

