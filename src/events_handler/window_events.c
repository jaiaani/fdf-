/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:59:40 by jados-sa          #+#    #+#             */
/*   Updated: 2025/04/29 19:59:42 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx.conn, data->img.ptr);
	mlx_destroy_window(data->mlx.conn, data->mlx.window);
	mlx_destroy_display(data->mlx.conn);
	free(data->mlx.conn);
	free_matrix(data->fdf.matrix, data->fdf.height);
	exit(1);
	return (0);
}
