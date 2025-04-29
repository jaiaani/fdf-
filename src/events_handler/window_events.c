/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:19:44 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/13 13:19:48 by jaiane           ###   ########.fr       */
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
