#include "fdf.h"

void	map_width(t_map *map, char *line)
{
	int	i;

	i = 0;
	map->width = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i])
			map->width++;
		while (line[i] && line[i] != ' ')
			i++;
	}
}

t_point	**empty_map(t_map *map)
{
	t_point	**matrix;
	int		i;

	matrix = (t_point **)malloc(sizeof(t_point *) * (map->height + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		matrix[i] = (t_point *)malloc(sizeof(t_point) * (map->width + 1));
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			return (NULL);
		}
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	map_init(t_map *map, int fd)
{
	char	*line;

	map->height = 1;
	line = get_next_line(fd);
	if (!line)
		return ;
	map_width(map, line);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		map->height++;
	}
    get_next_line(-1);
    map->matrix = empty_map(map);
    if (!map->matrix)
        return ;
}



// Fill Matrix

void	aparse_point(t_point *row, char *str, int i)
{
	char	**values;

	if (ft_strchr(str, ','))
	{
		values = ft_split(str, ',');
		if (!values)
			return ;
		row[i].value = fast_atoi(values[0]);
		row[i].color = color_number(values[1]);
		free_split(values);
	}
	else
	{
		row[i].value = fast_atoi(str);
		row[i].color = 0xffffff;
	}
}

void	afill_matrix_row(t_point *row, char *line)
{
	char	**row_values;
	int		i;

	row_values = ft_split(line, ' ');
	if (!row_values)
		return ;
	i = 0;
	while (row_values[i])
	{
		aparse_point(row, row_values[i], i);
		i++;
	}
	free_split(row_values);
}

void	afill_matrix(t_map *map, int fd)
{
	int		i;
	char	*line;


	i = 0;
	while (i < map->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		afill_matrix_row(map->matrix[i], line);
		free(line);
		i++;
	}
	get_next_line(-1);
}

// Parse map

t_map    parse_map(char *filepath)
{
    t_map   map;
    int     fd;

    fd = opened_fd(filepath);
    map_init(&map, fd);
    close(fd);
    fd = opened_fd(filepath);
    afill_matrix(&map, fd);
    return (map);
}