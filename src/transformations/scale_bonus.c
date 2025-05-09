#include "transformations.h"

void	apply_scale_factor(t_point_ *point ,t_params params)
{
	point->x *= params.sf_x + params.zoom;
	point->y *= params.sf_y + params.zoom;
	point->z *= params.sf_z + params.zoom;
}