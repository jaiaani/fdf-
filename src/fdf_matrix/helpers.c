/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:59:59 by jados-sa          #+#    #+#             */
/*   Updated: 2025/04/29 20:00:00 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fdf_width(t_fdf *fdf, char *line)
{
	int	i;

	i = 0;
	fdf->width = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i])
			fdf->width++;
		while (line[i] && line[i] != ' ')
			i++;
	}
}

void	fdf_init(t_fdf *fdf, int fd)
{
	char	*line;

	fdf->height = 1;
	line = get_next_line(fd);
	if (!line)
		return ;
	fdf_width(fdf, line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		fdf->height++;
	}
	fdf->center_x = fdf->width / 2.0f;
	fdf->center_y = fdf->height / 2.0f;
	get_next_line(-1);
}
