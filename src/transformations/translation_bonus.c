#include "../fdf.h"

void	apply_translation(t_point_ *point, t_params params)
{
    point->x += params.tf_x;
	point->y += params.tf_y;
	point->z += params.tf_z;
}
