/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:36:27 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/18 16:37:52 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}


void	apply_params_to_points(t_dot *dot, float *x1, float *y1, t_data *data)
{
	float	z1;

	dot->z = data->fdf.matrix[(int)dot->y][(int)dot->x].value;
	z1 = data->fdf.matrix[(int)*y1][(int)*x1].value;
	dot->color = data->fdf.matrix[(int)dot->y][(int)dot->x].color;
	apply_scale_factor(&dot->x, &dot->y, &dot->z, data->params);
	apply_scale_factor(x1, y1, &z1, data->params);
	apply_rotation(&dot->x, &dot->y, &dot->z, data->params);
	apply_rotation(x1, y1, &z1, data->params);
	apply_translation(&dot->x, &dot->y, &dot->z, data->params);
	apply_translation(x1, y1, &z1, data->params);
	isometric(&dot->x, &dot->y, dot->z);
	isometric(x1, y1, z1);
	dot->x += (data->w / 2) - data->fdf.center_x;
	dot->y += (data->h / 2) - data->fdf.center_y;
	*x1 += (data->w / 2) - data->fdf.center_x;
	*y1 += (data->h / 2) - data->fdf.center_y;
}
