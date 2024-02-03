/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:24:02 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/08 16:15:56 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
 #define RENDER_H

	# include "../cub3d.h"
	// # include "mlx.h"
	#define EPS 0.01
	# define HEIGHT 680
	# define WIDTH 700

	# define CUBE_FACTOR 64
	# define CUB3_FACTOR 64
	# define  FOV 60
	#define NUM_RAYS WIDTH

	int		render_window(t_data *data);


	/*          DEBUG           */
	
	size_t	get_longest_line(char **line);
	int		render_debug_window(t_data *data);
	int create_trgb(int r, int g, int b, int a);
	
	// int draw_line(int x, int y, int len, float degree, t_data *data);
	int draw_block(int x, int y, t_data *data);
	void draw_player(t_data *data);
	void cast_ray(t_data *data, t_ray *ray);
	void    render(t_data *data);
	double	dtor(double degree);
	double normalize1(double x);
	void	render_fc(t_data *data);
	void DDA(double X0, double Y0, double X1, double Y1, t_data *data);
	typedef struct s_inter
{
	//player position
    double x;
    double y;
	//grid position not rounded
	double P_x;
	double P_y;
	//steps calcul
	double Yp;
	double Xp;

    double ray_cos;
    double ray_sin;
	//intersect point
    double hit_x;
    double hit_y;
    int grid_x;
    int grid_y;
} t_inters;


#endif
