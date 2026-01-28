/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:15:29 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/07 10:19:54 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	draw_line_points(t_data *data, t_point p1, t_point p2)
{
	t_point	ip1;
	t_point	ip2;
	int		awm;
	int		ahm;

	ip1 = iso(data, p1);
	ip2 = iso(data, p2);
	awm = DRAW_WIDTH / 2 - data->map.extra_width;
	ahm = ((DRAW_HEIGHT / (data->map.y_max + 2)) * 2) - data->map.line_height
		- data->map.extra_height;
	render_p_line(data, (t_line){DRAW_WIDTH_START + awm + ip1.x,
		DRAW_HEIGHT_START + ahm + ip1.y, DRAW_WIDTH_START + awm + ip2.x,
		DRAW_HEIGHT_START + ahm + ip2.y, p1.z, p2.z});
}

static void	draw_x_lines(t_data *data)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = 0;
	while (y < data->map.y_max)
	{
		x = 0;
		while (x + 1 < data->map.x_max)
		{
			p1 = (t_point){data->map.line_width * x, data->map.line_height * y,
				data->map.matrix[y][x]};
			p2 = (t_point){data->map.line_width * (x + 1), data->map.line_height
				* y, data->map.matrix[y][x + 1]};
			draw_line_points(data, p1, p2);
			x++;
		}
		y++;
	}
}

static void	draw_y_lines(t_data *data)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	x = 0;
	while (x < data->map.x_max)
	{
		y = 0;
		while (y + 1 < data->map.y_max)
		{
			p1 = (t_point){data->map.line_width * x, data->map.line_height * y,
				data->map.matrix[y][x]};
			p2 = (t_point){data->map.line_width * x, data->map.line_height * (y
					+ 1), data->map.matrix[y + 1][x]};
			draw_line_points(data, p1, p2);
			y++;
		}
		x++;
	}
}

void	draw_map(t_data *data)
{
	draw_area(data, (t_rect){DRAW_WIDTH_START, DRAW_HEIGHT_START, DRAW_WIDTH,
		DRAW_HEIGHT, BLACK_PIXEL});
	draw_x_lines(data);
	draw_y_lines(data);
}
