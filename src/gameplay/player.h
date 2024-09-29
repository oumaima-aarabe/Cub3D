/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:53:56 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 18:36:24 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "../cub3d.h" 

t_pos	*set_player_pos(int x, int y, char rot, t_player *data);
t_pos	*move_player(float x, float y, t_map_data *data);

#endif
