#include "render.h"



int create_trgb(int r, int g, int b, int a);
void	render_fc(t_data *data)
{


    for (int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT / 2; j++)
        {
            mlx_put_pixel(data->map_image, i, j, 
            create_trgb(data->tex_data->C_R, data->tex_data->C_G, data->tex_data->C_B, 255));
        }
    }

    for (int i = 0; i < WIDTH; i++)
    {
        for(int j = HEIGHT / 2; j < HEIGHT; j++)
        {
            mlx_put_pixel(data->map_image, i, j, 
            create_trgb(data->tex_data->F_R, data->tex_data->F_G, data->tex_data->F_B, 255));
        }
    }
}