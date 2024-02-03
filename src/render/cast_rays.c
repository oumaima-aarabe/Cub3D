#include "render.h"

t_inters initilize_inter(t_data *data, t_ray *ray, int flag)
{
    t_inters A;

    // printf("%f\n",data->map_data->player->rot_angle);
    A.ray_cos = cos(ray->ray_ang);
    A.ray_sin = sin(ray->ray_ang);
    A.hit_x = 0;
    A.hit_y = 0;
    A.x = data->map_data->player->current_pos->x;
    A.y = data->map_data->player->current_pos->y;
    if (flag)
    {
        A.P_x = (A.ray_cos > 0) ? (floor(A.x / CUBE_FACTOR) * CUBE_FACTOR + CUBE_FACTOR) : 
            (floor(A.x / CUBE_FACTOR) * CUBE_FACTOR - 1);
        A.P_y = floor((A.y + (A.P_x - A.x) * tan(ray->ray_ang)));
        A.Xp = (A.ray_cos > 0) ? CUBE_FACTOR : -CUBE_FACTOR;
        A.Yp = A.Xp * tan(ray->ray_ang);

        // A.grid_x = (int)floor(A.P_x / CUBE_FACTOR);
        // A.grid_y = (int)floor(A.P_y / CUBE_FACTOR);
    }
    else 
    {
        A.P_y = (A.ray_sin < 0) ? (floor(A.y / CUBE_FACTOR) * CUBE_FACTOR) - 1 : 
        (floor(A.y / CUBE_FACTOR) * CUBE_FACTOR + CUBE_FACTOR);
        A.P_x = floor((A.x + (A.P_y - A.y) / tan(ray->ray_ang)));
        A.Yp = (A.ray_sin < 0) ? -CUBE_FACTOR : CUBE_FACTOR;
        A.Xp = A.Yp / tan(ray->ray_ang);
        // A.grid_x = (int)floor(A.P_x / CUBE_FACTOR);
        // A.grid_y = (int)floor(A.P_y / CUBE_FACTOR);
    }
    return (A);
}

void cast_vsingle_ray(t_data *data, t_ray *ray)
{
    t_inters A;
    
    A = initilize_inter(data, ray, 1);
    while (1)
    {
        A.grid_x = (int)floor(A.P_x / CUBE_FACTOR);
        A.grid_y = (int)floor(A.P_y / CUBE_FACTOR);
        if (A.grid_y < 0 || A.grid_y >= data->map_data->map_height || A.grid_x < 0 
        || A.grid_x >= data->map_data->map_width)
            return;
            if (data->map_data->mini_map[A.grid_y][A.grid_x] == '1')
            {
                A.hit_x = A.P_x;
                A.hit_y = A.P_y;
                break;
            }
        A.P_x += A.Xp;
        A.P_y += A.Yp;
    }
   ray->distance_v = sqrt(pow(A.hit_x - data->map_data->player->current_pos->x, 2) 
    + pow(A.hit_y - data->map_data->player->current_pos->y, 2));
    ray->x_col_v = A.hit_x;
    ray->y_col_v = A.hit_y;
}

void cast_hsingle_ray(t_data *data, t_ray *ray)
{
    
    t_inters A;
    
    A = initilize_inter(data, ray, 0);
     while (1)
    {
        A.grid_x = (int)floor(A.P_x / CUBE_FACTOR);
        A.grid_y = (int)floor(A.P_y / CUBE_FACTOR);
        // printf("hx : %d   y: %d\n", A.grid_x, A.grid_y);
        // printf("vx : %d   y: %d\n", A.P_x, A.P_y);
        // mlx_put_pixel(data->map_image,A.P_x, A.P_y,0XFF0FF0);
        if (A.grid_y < 0 || A.grid_y >= data->map_data->map_height || A.grid_x < 0 
        || A.grid_x >= data->map_data->map_width)
            return;
            if (data->map_data->mini_map[A.grid_y][A.grid_x] == '1')
            {
                A.hit_x = A.P_x;
                A.hit_y = A.P_y;
                break;
            }
        A.P_x += A.Xp;
        A.P_y += A.Yp;
    }
    ray->distance_h = sqrt(pow(A.hit_x - data->map_data->player->current_pos->x, 2) + 
	pow(A.hit_y - data->map_data->player->current_pos->y, 2));
    ray->x_col_h = A.hit_x;
    ray->y_col_h = A.hit_y;
}


void cast_ray(t_data *data, t_ray *ray)
{
    ray->distance_h = LONG_MAX;
    ray->distance_v = LONG_MAX;
    // if (fabs(cos(ray->ray_ang)) > EPS)
        cast_hsingle_ray(data, ray);
    // if (fabs(sin(ray->ray_ang)) > EPS)
        cast_vsingle_ray(data, ray);
    ray->flag = (ray->distance_h > ray->distance_v) ? 1 : 2;
    // printf("h : %f v : %f\n", ray->distance_h, ray->distance_v);
    if (ray->flag == 1)
    {
        ray->f_d = ray->distance_v;
        ray->f_x = ray->x_col_v;
        ray->f_y = ray->y_col_v;
    }
    else
    {
        ray->f_d = ray->distance_h;
        ray->f_x = ray->x_col_h;
        ray->f_y = ray->y_col_h;
    }
    // for (int i = 0; i < 50; i++)
    // {
    //     mlx_put_pixel(data->player_image, 5 + i, 5 + i, 0XFF0FF0);
    // }
    
    // mlx_put_pixel(data->player_image, ray->f_x, ray->f_y, 0XFF0FF0);
    // printf("%f\n", ray->f_d);
    // if (ray->f_d != WIDTH)
    // {
    //     DDA(data->map_data->player->current_pos->x, data->map_data->player->current_pos->y, ray->f_x, ray->f_y, data);
    //     // mlx_image_to_window(data->mlx, data->player_image, 0, 0);
    // }
}

