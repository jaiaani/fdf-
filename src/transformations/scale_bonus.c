#include "../fdf.h"

void	apply_scale_factor(float *x, float *y, float *z, t_params params)
{
	*x *= params.sf_x + params.zoom;
	*y *= params.sf_y + params.zoom;
	*z *= params.sf_z + params.zoom;
}