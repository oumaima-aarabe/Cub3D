/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouaarabe <ouaarabe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:37:35 by ichaiq            #+#    #+#             */
/*   Updated: 2024/01/03 18:48:08 by ouaarabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int check_cords(int x, int y, t_data *data, int i)
{
	int xRaw;
	int yRaw;

	xRaw = (int)floor(x / CUBE_FACTOR);
	yRaw = (int)floor(y / CUBE_FACTOR);
	// printf("x: %d, y: %d\n", yRaw, xRaw);
	if (yRaw >= 0 && yRaw < HEIGHT/CUBE_FACTOR && xRaw >= 0 && xRaw < ft_strlen(data->map_data->mini_map[yRaw])) 
	{
		if ( data->map_data->mini_map[yRaw][xRaw] == '1')
			return (0);
		return 1;
	}
	return (0);
}

int draw_line2(int len, float degree, t_data **data, int j)
{
	(void)len;
    float angRad = degree * M_PI / 180.0;
    float xInc = cos(angRad);
    float yInc = sin(angRad);
	// int j = 0;
    for (int i = 0; i < WIDTH; i++)
    {
        int xPos = (*data)->map_data->player->current_pos->x + (int)(xInc * i + 0.5);
        int yPos = (*data)->map_data->player->current_pos->y + (int)(yInc * i + 0.5);
		if (!check_cords(xPos, yPos, (*data), j))
			break;
        if (xPos >= 0 && xPos < WIDTH && yPos >= 0 && yPos < HEIGHT / 2)
            mlx_put_pixel((*data)->player_image, xPos, yPos, 0X0000FF);
    }
    return 1;
}

int draw_block(int x, int y, t_data *data)
{
	int i;
	int c = 0;
	int rgb;

	if (data->map_data->mini_map[x][y] == '1')
		rgb = 0X32a858;
	else if (data->map_data->mini_map[x][y] == '0')
		rgb = 0Xffffd9;
	else
		rgb = 0X111fd9;	
	while (c < CUBE_FACTOR)
	{
		i = 0;
		while (i < CUBE_FACTOR)
		{
			mlx_put_pixel(data->map_image, (y * CUBE_FACTOR) + i,
				(x * CUBE_FACTOR) + c, rgb);
			i++;
		}
		c++;
	}
	c = 0;
	while (c < CUBE_FACTOR)
	{
		mlx_put_pixel(data->map_image, (y * CUBE_FACTOR) + 0,
			(x * CUBE_FACTOR) + c, 0x000FFF);
		mlx_put_pixel(data->map_image, (y * CUBE_FACTOR) + c,
			(x * CUBE_FACTOR) + 0, 0x000FFF);
		c++;
	}
	return (1);
}

void draw_player(t_data *data)
{
	int x;
	int y;
	float nang;
	float i;

	x = 0;
	y = 0;
	i = -30;
	if (data->player_image)
		mlx_delete_image(data->mlx, data->player_image);
	data->player_image =  mlx_new_image(data->mlx, WIDTH, HEIGHT);
	// nang = (data->map_data->player->rot_angle) * (180 / M_PI);
	nang = (data->map_data->player->rot_angle) ;
	// printf("nang after angle : %f\n", nang);

	// int i = 0;
	float stepRays =   60.0 / (WIDTH );
	// printf("stepRays : %f\n",stepRays); 

	// while(i < 30){
		// draw_line2(64, nang + i, &data, i + 30);
	// 	i += stepRays;	
	// }
    // DDA(data->map_data->player->current_pos->x, data->map_data->player->current_pos->y, 
	// data->map_data->player->current_pos->x + cos(nang) * 60, data->map_data->player->current_pos->y + sin(nang) * 60, data);
	mlx_put_pixel(data->player_image, data->map_data->player->current_pos->x,
	 data->map_data->player->current_pos->y, 0X0000FF);
	// cast_ray(data, nang);

	// for (float i = -30; i < 30; i = i + stepRays)
	// puts("here");
	mlx_image_to_window(data->mlx, data->player_image, 0,0);
}



