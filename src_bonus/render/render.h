/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichaiq <ichaiq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:24:02 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/13 23:23:38 by ichaiq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define EPS 0.00000001
# define HEIGHT 720
# define WIDTH 1280

# define CUB3_FACTOR 64
# define FOV 60
# define NUM_RAYS WIDTH

# include "../cub3d.h"
	// # include "mlx.h"

typedef struct s_inter
{
	double	p_x;
	double	p_y;
	double	ray_cos;
	double	ray_sin;
}	t_inters;

typedef struct s_minimap
{
	int		beg_x;
	int		beg_y;
	float	px;
	float	py;
	int		grid_x;
	int		grid_y;
}	t_mini;
typedef struct s_wrg
{
	int	i;
	int	j;
}	t_wrg;

typedef struct s_ray_wall
{
	int		col;
	double	wall_h;
	t_wrg	wrg;
}			t_ray_wall;

double		dtor(double degree);
int			render_window(t_data *data);
int			init_mlx_world(t_data *data);
int			init_mlx_data(t_data *data);
void		cast_ray(t_data *data, t_ray *ray);
int			wall_ray_collision(float posx, float posy, t_data *data);
void		init_ray(t_ray *ray);
float		normalize(float angle);

/*			CALCUL			*/
void		calcul_v_right(t_data *data, t_ray *ray, t_inters *A);
void		calcul_v_left(t_data *data, t_ray *ray, t_inters *A);
void		calcul_h_up(t_data *data, t_ray *ray, t_inters *A);
void		calcul_h_down(t_data *data, t_ray *ray, t_inters *A);

/*          DEBUG           */

size_t		get_longest_line(char **line);
int			render_debug_window(t_data *data);
int			create_trgb(int r, int g, int b, int a);
int			get_color_pixel(int j, mlx_image_t tex, t_ray ray);
int			draw_block(int x, int y, t_data *data);
void		cast_ray(t_data *data, t_ray *ray);
void		render(t_data *data);
double		dtor(double degree);
void		render_fc(t_data *data);
t_wall_pos	*get_wall_cords(t_ray ray);
mlx_image_t	*get_dir_tex(t_textures_data *tdata, t_direction dir);
void		render_world(void *Data);
void		handle_mlx_close(void *param);
void		draw_2d_map(t_data *data);
#endif
