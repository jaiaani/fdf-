#include "../fdf.h"

void	apply_translation(float *x, float *y, float *z, t_params params)
{
	*x += params.tf_x;
	*y += params.tf_y;
	*z += params.tf_z;
}