/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:41:46 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/05 01:52:13 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H 

		#include <unistd.h>
		#include "../includes/libft/libft.h"
		#include "../includes/gnl/get_next_line_bonus.h"

		# include "../includes/MLX42/include/MLX42/MLX42.h"
		#include <stdio.h>
		#include <stdlib.h>
		#include <fcntl.h>
		#include <math.h>

		typedef struct s_textures_data {
			char *NO_path;
			char *SO_path;
			char *WE_path;
			char *EA_path;

			
			mlx_texture_t *NO_texture;
			mlx_texture_t *SO_texture;
			mlx_texture_t *WE_texture;
			mlx_texture_t *EA_texture;

			mlx_image_t *NO_image;
			mlx_image_t *SO_image;
			mlx_image_t *WE_image;
			mlx_image_t *EA_image;
			
			int F_R;
			int F_G;
			int F_B;
			int isFValide;
			
			int C_R;
			int C_G;
			int C_B;
			int isCValide;

		}				t_textures_data;

		typedef struct s_pos{
			float x;
			float y;
		}				t_pos;

		typedef struct s_player{
			t_pos	*current_pos;
			t_pos	*start_pos;
			double	rot_angle;
			double	d;
		}				t_player;
		
		typedef struct s_map_data{
			char **mini_map;
			int map_height;
			int map_width;
			int map3_height;
			int map3_width;
			int hasPlayer;
			t_player *player;
			char **map;
			
			
		}				t_map_data;
		
		
		typedef struct s_ray
		 {
			double ray_ang;
			double distance_v;
			double distance_h;
			double f_d;
			double x_col_v;
			double y_col_v;
			double f_x;
			double f_y;
			double x_col_h;
			double y_col_h;
			int flag;

		}t_ray;

		typedef struct s_wrg
		{
			int i;
			int j;
		}	t_wrg;

		
		typedef struct s_data {
			
			char *map_filename;
			int file_count_lines;

			t_textures_data *tex_data;
			t_map_data		*map_data;


			mlx_t *mlx;
			mlx_image_t *map_image;
			mlx_image_t *player_image;
		}				t_data;

		#include "parser/parser.h"
		#include "utils/utils.h"
		#include "render/render.h"
		#include "gameplay/player.h"


#endif
