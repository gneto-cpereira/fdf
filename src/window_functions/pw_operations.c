/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:27:06 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/26 11:48:27 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	setup_image(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
}

void	setup_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0L, (int (*)())handle_close, data);
	mlx_loop(data->mlx_ptr);
}

int	initialize_data(t_data *data, t_map map)
{
	data->map = map;
	data->should_close = 0;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"fdf");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	return (0);
}

void	free_mlx_stuff(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_printf("\nWindow closed\n");
}

int	handle_close(t_data *data)
{
	data->should_close = 1;
	return (0);
}
