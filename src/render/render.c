#include "render.h"


void DDA(double X0, double Y0, double X1, double Y1, t_data *data)
{ 
    // calculate dx & dy 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float)steps; 
    float Yinc = dy / (float)steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) { 
       mlx_put_pixel(data->player_image, X, Y, 0XFF0FF0); // put pixel at (X,Y) 
        X += Xinc; // increment in x at each step 
        Y += Yinc; // increment in y at each step  // for visualization of line- 
                    // generation step by step 
    } 
} 

double intercept_th(t_ray ray, t_data *data)
{
	double a =   ray.f_d * cos(data->map_data->player->rot_angle - ray.ray_ang );
	double b = (WIDTH / 2) / tan(dtor(FOV / 2));
    double c = (double)CUBE_FACTOR;
	return((c / a) * b);
}


void    render(t_data *data)
{
    t_ray ray;
	t_wrg rg;


    double  wall_h;
    double h_value;
    int i = -1;
    ray.ray_ang = normalize1(data->map_data->player->rot_angle  - (dtor(FOV / 2)));
    while (++i < WIDTH)
    {
        cast_ray(data, &ray);
		wall_h = intercept_th(ray, data);
        if (wall_h > HEIGHT)
            wall_h = HEIGHT;
		rg.i = (HEIGHT / 2) - (wall_h / 2);
		rg.j = (HEIGHT / 2) + (wall_h / 2);
        for (int j = rg.i; j < rg.j; j++)
            mlx_put_pixel(data->map_image,i,  j, 0XFF0000);
        ray.ray_ang = normalize1(ray.ray_ang  +( dtor(FOV) / WIDTH));
    }

}
