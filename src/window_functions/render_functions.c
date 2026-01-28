/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:24:00 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/23 11:48:50 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void render_background(t_img *img, int color)
{
	int i;
	int j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int calc_up_color(t_data *data, int z)
{
	return ((z * (COLOR_MAX)) / op_not_zero(data->map.z_max - data->map.z_min));
}

int calc_down_color(t_data *data, int z)
{
	return (((data->map.z_max - z) * (COLOR_MIN)) / op_not_zero(data->map.z_max - data->map.z_min));
}

void draw_area(t_data *data, t_rect sqr)
{
    render_line(data, (t_line){.x0 = sqr.x, .y0 = sqr.y, .x1 = sqr.x + sqr.width, .y1 = sqr.y});
    render_line(data, (t_line){.x0 = sqr.x, .y0 = sqr.y, .x1 = sqr.x, .y1 = sqr.y + sqr.height});
    render_line(data, (t_line){.x0 = sqr.x + sqr.width, .y0 = sqr.y, .x1 = sqr.x + sqr.width, .y1 = sqr.y + sqr.height});
    render_line(data, (t_line){.x0 = sqr.x, .y0 = sqr.y + sqr.height, .x1 = sqr.x + sqr.width, .y1 = sqr.y + sqr.height});
}