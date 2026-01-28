/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:50:55 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/28 11:09:30 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int max(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	else
	{
		return (b);
	}
}

static void render_line_2(t_data *data, t_line line, t_rl rl)
{
	while (1)
	{
		img_pix_put(&data->img, line.x0, line.y0, BORDERS_COLOR);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break;
		rl.e2 = 2 * rl.err;
		if (rl.e2 > -rl.dy)
		{
			rl.err = rl.err - rl.dy;
			line.x0 = line.x0 + rl.sx;
		}
		if (rl.e2 < rl.dx)
		{
			rl.err = rl.err + rl.dx;
			line.y0 = line.y0 + rl.sy;
		}
	}
}

void render_line(t_data *data, t_line line)
{
	t_rl rl;
	rl.dx = abs(line.x1 - line.x0);
	rl.dy = abs(line.y1 - line.y0);
	if (line.x0 < line.x1)
		rl.sx = 1;
	else
		rl.sx = -1;
	if (line.y0 < line.y1)
		rl.sy = 1;
	else
		rl.sy = -1;
	rl.err = rl.dx - rl.dy;
	render_line_2(data, line, rl);
}
