/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:59:22 by jados-sa          #+#    #+#             */
/*   Updated: 2025/04/29 19:59:25 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	event_handler(int keysym, t_data *data)
{
	int	redraw;

	redraw = 0;
	if (keysym == XK_Escape)
		close_window(data);
	zoom(keysym, data, &redraw);
	scale(keysym, data, &redraw);
	rotate(keysym, data, &redraw);
	translate(keysym, data, &redraw);
	reset(keysym, data, &redraw);
	if (redraw)
	{
		mlx_destroy_image(data->mlx.conn, data->img.ptr);
		mlx_clear_window(data->mlx.conn, data->mlx.window);
		draw(data);
	}
	return (0);
}
