/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:59:09 by jados-sa          #+#    #+#             */
/*   Updated: 2025/04/29 19:59:12 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*d;

	if (x >= 0 && x < data->w && y >= 0 && y < data->h)
	{
		d = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
		*(unsigned int *)d = color;
	}
}
