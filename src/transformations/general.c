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

#include "transformations.h"

void	apply_params_to_points(t_point_ *a, t_point_ *b, t_data *data)
{
	a->z= data->map.matrix[(int)b->y][(int)b->x].value;
	b->z = data->map.matrix[(int)b->y][(int)b->x].value;
	apply_scale_factor(a, data->params);
	apply_scale_factor(b, data->params);
	apply_rotation(a, data->params);
	apply_rotation(b, data->params);
	apply_translation(a, data->params);
	apply_translation(b, data->params);
	isometric(a);
	isometric(b);
	a->x += (data->w / 2) - data->fdf.center_x;
	a->y += (data->h / 2) - data->fdf.center_y;
	b->x += (data->w / 2) - data->fdf.center_x;
	b->y += (data->h / 2) - data->fdf.center_y;
}
