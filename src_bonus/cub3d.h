/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 22:41:46 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 23:36:21 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H 
# include <unistd.h>
# include "../includes/libft/libft.h"
# include "../includes/gnl/get_next_line_bonus.h"
# include "/Users/ichaiq/Desktop/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define CUBE_FACTOR 64

typedef struct s_textures_data
{
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	mlx_texture_t	*north_texture;
	mlx_texture_t	*south_texture;
	mlx_texture_t	*west_texture;
	mlx_texture_t	*east_texture;
	mlx_image_t		*north_image;
	mlx_image_t		*south_image;
	mlx_image_t		*west_image;
	mlx_image_t		*east_image;
	int				f_r;
	int				f_g;
	int				f_b;
	int				isf_valide;
	int				c_r;
	int				c_g;
	int				c_b;
	int				isc_valide;

}				t_textures_data;

typedef struct s_pos
{
	float	x;
	float	y;
}				t_pos;
typedef struct s_wall_pos
{
	float	x;
	float	y;
	float	wall_x;
	float	wall_y;
}				t_wall_pos;

typedef struct s_player
{
	t_pos	*current_pos;
	t_pos	*start_pos;
	double	rot_angle;
	double	d;
}				t_player;

typedef struct s_map_data
{
	char		**mini_map;
	int			map_height;
	int			map_width;
	int			hasplayer;
	t_player	*player;
	char		**map;
}				t_map_data;

typedef struct s_direction
{
	bool	horizontal;
	bool	north;
	bool	south;
	bool	vertical;
	bool	west;
	bool	east;

}	t_direction;

typedef struct s_ray
{
	double		ray_ang;
	double		distance_v;
	double		distance_h;
	double		f_d;
	double		x_col_v;
	double		y_col_v;
	double		f_x;
	double		f_y;
	double		x_col_h;
	double		y_col_h;
	int			flag;
	t_direction	dir;
}	t_ray;

typedef struct s_data
{
	char			*map_filename;
	int				file_count_lines;
	t_textures_data	*tex_data;
	t_map_data		*map_data;
	mlx_t			*mlx;
	mlx_image_t		*window_image;
	mlx_image_t		*player_image;
	double			mouse_x;
	double			mouse_y;
}				t_data;
#endif
