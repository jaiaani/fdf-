
#ifndef TRANSFORMATIONS_H
# define TRANSFORMATIONS_H

#include "../fdf.h"

void	apply_rotation(t_point_ *point, t_params params);
void	apply_translation(t_point_ *point, t_params params);
void	apply_scale_factor(t_point_ *point ,t_params params);

#endif