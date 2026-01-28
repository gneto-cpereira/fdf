/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:09:59 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/26 11:48:03 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// thats what will repeat every time in mlx cycle
int	render(t_data *data)
{
	if (data->should_close)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	if (!data->win_ptr)
		return (1);
	render_background(&data->img, BLACK_PIXEL);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	return (0);
}

// pw -> projection window
int	pw(t_map map)
{
	t_data	data;

	if (initialize_data(&data, map) == MLX_ERROR)
		return (MLX_ERROR);
	setup_image(&data);
	setup_hooks(&data);
	free_mlx_stuff(&data);
	return (0);
}
