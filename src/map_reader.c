/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:58:11 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/08 20:23:30 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(int **matrix, int matrix_len)
{
	int	i;

	i = 0;
	while (i < matrix_len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static int	*line_to_vector(char *line, t_map *map)
{
	int		*vector;
	int		i;
	char	**str;

	str = ft_split(line, ' ');
	vector = malloc(sizeof(int) * (ft_arraylen(str)));
	i = 0;
	while (str[i])
	{
		vector[i] = atoi(str[i]);
		if (atoi(str[i]) > map->z_max)
			map->z_max = atoi(str[i]);
		if (atoi(str[i]) < map->z_min)
			map->z_min = atoi(str[i]);
		i++;
	}
	map->x_max = i;
	ft_free_array(str);
	return (vector);
}

static void	map_initializations(t_map *map)
{
	map->line_width = LINE_WIDTH;
	map->line_height = LINE_HEIGHT;
	map->extra_width = EXTRA_WIDTH;
	map->extra_height = EXTRA_HEIGHT;
	map->extra_angle = 0;
	map->extra_vertical_angle = 0;
	map->extra_color = 130;
	map->extra_z = EXTRA_Z;
}

t_map	get_file_coordinates(char *file_name, int y_max)
{
	t_map	map;
	int		fd;
	int		i;
	char	*str;

	map.z_max = 0;
	map.z_min = 0;
	i = 0;
	fd = open(file_name, O_RDONLY);
	if (!fd)
		return ((t_map){0});
	map.matrix = malloc(sizeof(int *) * y_max);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		map.matrix[i] = line_to_vector(str, &map);
		free(str);
		i++;
	}
	map.y_max = i;
	map_initializations(&map);
	close(fd);
	return (map);
}
