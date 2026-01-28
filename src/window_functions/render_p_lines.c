/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_p_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:50:55 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/28 11:16:47 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// Função para interpolar linearmente entre duas cores
int interpolate_color(int color1, int color2, float factor)
{
	t_colors c;

	c.red1 = (color1 >> 16) & 0xFF;
	c.green1 = (color1 >> 8) & 0xFF;
	c.blue1 = color1 & 0xFF;
	c.red2 = (color2 >> 16) & 0xFF;
	c.green2 = (color2 >> 8) & 0xFF;
	c.blue2 = color2 & 0xFF;
	c.interpolated_red = (int)(c.red1 + (c.red2 - c.red1) * factor);
	c.interpolated_green = (int)(c.green1 + (c.green2 - c.green1) * factor);
	c.interpolated_blue = (int)(c.blue1 + (c.blue2 - c.blue1) * factor);
	return ((c.interpolated_red << 16) | (c.interpolated_green << 8) | c.interpolated_blue);
}

static void color_management(t_data *data, t_color_management *t, t_line line)
{
	t->interpolation_factor = (float)t->step / t->total_steps;
	t->initial_color = ft_rgb_to_int(calc_down_color(data, line.z0) + data->map.extra_color, calc_up_color(data, line.z0), 250 - data->map.extra_color);
	t->final_color = ft_rgb_to_int(calc_down_color(data, line.z1) + data->map.extra_color, calc_up_color(data, line.z1), 250 - data->map.extra_color);
	t->interpolated_color = interpolate_color(t->initial_color, t->final_color,
											  t->interpolation_factor);
}

static void line_management(t_line *line, int *z, t_rl *rl)
{
	rl->e2 = 2 * rl->err;
	if (rl->e2 > -rl->dy)
	{
		rl->err -= rl->dy;
		line->x0 += rl->sx;
	}
	if (rl->e2 < rl->dx)
	{
		rl->err += rl->dx;
		line->y0 += rl->sy;
		z += rl->z_increment;
	}
}

// algoritmo de Bresenham
// render line do normal lines
// render p line do projection lines
static void render_p_line_2(t_data *data, t_line line, t_rl rl, int z)
{
	t_color_management t;

	t.delta_z = line.z1 - line.z0;
	t.total_steps = max(abs(line.x1 - line.x0), abs(line.y1 - line.y0));
	t.step = 0;
	while (1)
	{
		color_management(data, &t, line);
		if (line.x0 > DRAW_WIDTH_START && line.x0 < DRAW_WIDTH + DRAW_WIDTH_START && line.y0 > DRAW_HEIGHT_START && line.y0 < DRAW_HEIGHT + DRAW_HEIGHT_START)
		{
			img_pix_put(&data->img, line.x0, line.y0, t.interpolated_color);
		}
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break;
		line_management(&line, &z, &rl);
		t.step++;
	}
}

void render_p_line(t_data *data, t_line line)
{
	t_rl rl;
	int delta_z;
	int total_steps;
	int z;

	z = line.z0;
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
	delta_z = line.z1 - line.z0;
	total_steps = max(abs(line.x1 - line.x0), abs(line.y1 - line.y0));
	rl.z_increment = (float)delta_z / total_steps;
	render_p_line_2(data, line, rl, z);
}
