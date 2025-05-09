#include "fdf.h"

int	mod_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	max_num(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	bresenham(t_point_ a, t_point_ b, t_data *data)
{
	float	x_step;
	float	y_step;
	float	max;
    int     color;

    color = data->map.matrix[(int)a.y][(int)a.x].color;
    printf("%x", color)
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = max_num(mod_abs(x_step), mod_abs(y_step));
	x_step /= max;
	y_step /= max;
	while (int)(a.x - b.x) || (int)(a.y - b.y))
	{
		my_mlx_pixel_put(data, a.x, a.y, #0ffffff);
		a.x += x_step;
		a.y += y_step;
	}
}

void	draw_line(t_dot dot, float x1, float y1, t_data *data)
{
	apply_params_to_points(&dot, &x1, &y1, data);
	bresenham(dot, x1, y1, data);
}

int	draw(t_data *data)
{
	t_point_   a;
    t_point_   b;

	data->img.ptr = mlx_new_image(data->mlx.conn, data->w, data->h);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	a.y = 0;
	while (a.y < data->map.height)
	{
		a.x = 0;
		while (a.x < data->map.width)
		{
			if (x < data->map.width - 1)
            {
                b.x = a.x + 1;
                b.y = a.y;
                draw_line(a, b, data);
            }
				
			if (y < data->map.height - 1)
            {
                b.x = a.x;
                b.y = a.y + 1;
                draw_line(a, b, data);
            }
			a.x++;
		}
		a.y++;
	}
	mlx_put_image_to_window(data->mlx.conn, data->mlx.window,
		data->img.ptr, 0, 0);
	display_menu(data);
	return (0);
}
