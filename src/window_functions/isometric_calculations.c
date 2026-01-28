/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_calculations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:30:59 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/08 20:08:34 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// isometric_calculations
t_point	iso(t_data *data, t_point p)
{
	t_point			p2;
	t_iso_config	c;

	c.height = 100;
	c.z_scale = data->map.extra_z;
	c.angle = 45 + data->map.extra_angle;
	c.vertical_angle = 45 + data->map.extra_vertical_angle;
	c.radian_angle = c.angle * M_PI / 180.0;
	c.radian_vertical_angle = c.vertical_angle * M_PI / 180.0;
	p2.x = (p.x - p.y) * cos(c.radian_angle);
	p2.y = (p.x + p.y) * sin(c.radian_angle) * cos(c.radian_vertical_angle)
		- p.z * c.z_scale * sin(c.radian_vertical_angle);
	p2.y -= c.height;
	return (p2);
}
