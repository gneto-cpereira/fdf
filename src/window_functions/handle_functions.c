/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:06:48 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/23 11:03:04 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// arrows 			to rotation
// r and f 			to height
// x 				to reset all configs
static void	handle_keypress3(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		data->map.extra_angle += 5;
	if (keysym == XK_Right)
		data->map.extra_angle -= 5;
	if (keysym == XK_Up)
		data->map.extra_vertical_angle += 5;
	if (keysym == XK_Down)
		data->map.extra_vertical_angle -= 5;
	if (keysym == XK_r)
		data->map.extra_z += 1;
	if (keysym == XK_f)
		data->map.extra_z -= 1;
	if (keysym == XK_x)
	{
		data->map.line_width = LINE_WIDTH;
		data->map.line_height = LINE_HEIGHT;
		data->map.extra_width = EXTRA_WIDTH;
		data->map.extra_height = EXTRA_HEIGHT;
		data->map.extra_z = EXTRA_Z;
		data->map.extra_angle = EXTRA_ANGLE;
		data->map.extra_vertical_angle = EXTRA_ANGLE;
		data->map.extra_color = EXTRA_COLOR;
	}
}

// a, d, w and s 	to movement
// q and e 			to increase speed
// v and c			to change colors
// Esc				to close all
static void	handle_keypress2(int keysym, t_data *data)
{
	static int	speed = 5;

	if (keysym == XK_e)
		speed++;
	if (keysym == XK_q)
		speed--;
	if (keysym == XK_w)
		data->map.extra_height += speed;
	if (keysym == XK_s)
		data->map.extra_height -= speed;
	if (keysym == XK_a)
		data->map.extra_width += speed;
	if (keysym == XK_d)
		data->map.extra_width -= speed;
	if (keysym == XK_v && data->map.extra_color < 220)
		data->map.extra_color += 2;
	if (keysym == XK_c && data->map.extra_color > 0)
		data->map.extra_color -= 2;
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
}

// i and o 			to zoom in/out
// calling all the others handles
int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_i)
	{
		data->map.extra_z += 0.5;
		data->map.line_width++;
		data->map.line_height++;
	}
	if (keysym == XK_o && data->map.line_width > 0)
	{
		data->map.line_width--;
		data->map.line_height--;
	}
	handle_keypress2(keysym, data);
	handle_keypress3(keysym, data);
	return (0);
}
