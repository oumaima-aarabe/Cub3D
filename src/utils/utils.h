/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:55:24 by ichaiq            #+#    #+#             */
/*   Updated: 2023/11/04 15:01:23 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "../cub3d.h"

void free_arr(char **arr);
int get_count_line(char *filename);
int ft_isnumber (char *s);
char *get_clear_line(int fd);
t_textures_data *init_texture_struct();

#endif