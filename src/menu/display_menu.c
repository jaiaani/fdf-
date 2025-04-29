/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:46:47 by jados-sa          #+#    #+#             */
/*   Updated: 2025/04/29 20:46:50 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	display_menu(t_data *data)
{
	char	*menu;
	int		y_margin;

	y_margin = 30;
	menu = "------- [FDF] Menu -------";
	mlx_string_put(data->mlx.conn, data->mlx.window, X_MARGIN, y_margin,
		0x03fc35, menu);
	axes_menu(data, &y_margin);
	instructions(data);
}
