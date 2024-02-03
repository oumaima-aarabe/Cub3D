/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:56 by ichaiq            #+#    #+#             */
/*   Updated: 2023/12/24 01:57:22 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
    #define PLAYER_H

    #include "../cub3d.h" 

    t_pos   *set_player_pos(int x, int y, char rot, t_player * data);
    t_pos   *move_player(float x, float y, t_map_data *data);
#endif
