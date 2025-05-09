#include "transformations.h"

void	apply_x_rotation(t_point_ *point, t_params params)
{
	float	angle_rad;
	float	y_temp;
	float	z_temp;

	if (params.x_angle == 0)
		return ;
	angle_rad = params.x_angle * (M_PI / 180);
	y_temp = point->y;
	z_temp = point->z;
	point->y = y_temp * cos(angle_rad) - z_temp * sin(angle_rad);
	point->z = y_temp * sin(angle_rad) + z_temp * cos(angle_rad);
}

void	apply_y_rotation(t_point_ *point, t_params params)
{
	float	angle_rad;
	float	x_temp;
	float	z_temp;

	if (params.y_angle == 0)
		return ;
	angle_rad = params.y_angle * (M_PI / 180);
	x_temp = point->x;
	z_temp = point->z;
	point->x = x_temp * cos(angle_rad) + z_temp * sin(angle_rad);
	point->z = -x_temp * sin(angle_rad) + z_temp * cos(angle_rad);
}

void	apply_z_rotation(t_point_ *point, t_params params)
{
	float	angle_rad;
	float	x_temp;
	float	y_temp;

	if (params.z_angle == 0)
		return ;
	angle_rad = params.z_angle * (M_PI / 180);
	x_temp = point->x;
	y_temp = point->y;
	point->x = x_temp * cos(angle_rad) - y_temp * sin(angle_rad);
	point->y = x_temp * sin(angle_rad) + y_temp * cos(angle_rad);
}

void	apply_rotation(t_point_ *point, t_params params)
{
	apply_z_rotation(point, params);
	apply_y_rotation(point, params);
	apply_x_rotation(point, params);
}