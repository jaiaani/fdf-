/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axes.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:00:42 by jados-sa          #+#    #+#             */
/*   Updated: 2025/04/29 20:00:43 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	x_menu(t_data *data, int *y_margin)
{
	char	*menu;

	*y_margin += 15;
	menu = "| - - - - - x-axis - - - - --|";
	mlx_string_put(data->mlx.conn, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	scaling_factor(data, y_margin, data->params.sf_x);
	translation_factor(data, y_margin, data->params.tf_x);
	rotation_angle(data, y_margin, data->params.x_angle);
}

void	y_menu(t_data *data, int *y_margin)
{
	char	*menu;

	*y_margin += 15;
	menu = "| - - - - - y-axis - - - - --|";
	mlx_string_put(data->mlx.conn, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	scaling_factor(data, y_margin, data->params.sf_y);
	translation_factor(data, y_margin, data->params.tf_y);
	rotation_angle(data, y_margin, data->params.y_angle);
}

void	z_menu(t_data *data, int *y_margin)
{
	char	*menu;

	*y_margin += 15;
	menu = "| - - - - - z-axis - - - - --|";
	mlx_string_put(data->mlx.conn, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	scaling_factor(data, y_margin, data->params.sf_z);
	translation_factor(data, y_margin, data->params.tf_z);
	rotation_angle(data, y_margin, data->params.z_angle);
}

void	axes_menu(t_data *data, int *y_margin)
{
	x_menu(data, y_margin);
	y_menu(data, y_margin);
	z_menu(data, y_margin);
}
