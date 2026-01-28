/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:01:08 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/28 11:10:21 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* *********************************** */
/*                                     */
/*             FDF HEADER              */
/*                                     */
/* *********************************** */

# include "../libs/libft/libft.h"
# include "../libs/mlx_linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_map
{
	int		**matrix;
	int		x_max;
	int		y_max;
	int		z_max;
	int		z_min;
	int		line_width;
	int		line_height;
	int		extra_width;
	int		extra_height;
	int		extra_angle;
	int		extra_vertical_angle;
	int		extra_z;
	int		extra_color;
}			t_map;

void		fdf(char *file);
t_map		get_file_coordinates(char *file_name, int y_max);
void		free_matrix(int **matrix, int matrix_len);

/* *********************************** */
/*                                     */
/*           WINDOW_FUNCTIONS          */
/*                                     */
/* *********************************** */

// window parameters
// -window
# define WINDOW_WIDTH 1500
# define WINDOW_HEIGHT 900
# define W_WIDTH_CENTER 750 // WINDOW_WIDTH / 2
# define W_HEIGHT_CENTER 450 // WINDOW_HEIGHT / 2
// -margin
# define MARGIN_WIDTH 95 // WINDOW_WIDTH * 0.05
# define MARGIN_HEIGHT 45 // WINDOW_WIDTH * 0.05
// -draw area
# define DRAW_WIDTH_START MARGIN_WIDTH
# define DRAW_WIDTH 1350 // (WINDOW_WIDTH * 0.90)
# define DRAW_HEIGHT_START MARGIN_HEIGHT
# define DRAW_HEIGHT 720 // (WINDOW_HEIGHT * 0.80)
// -figuredf/blob/main/fdf_files/fdf.h
# define LINE_WIDTH 20
# define LINE_HEIGHT 20
# define EXTRA_WIDTH 0
# define EXTRA_HEIGHT -300
# define EXTRA_Z 3
# define EXTRA_ANGLE 0
# define EXTRA_COLOR 0
// -others
# define WINDOW_NAME "fdf"
# define MLX_ERROR 1
//
//
// colors
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF
# define BLACK_PIXEL 0x000000
# define UPPER_COLOR RED_PIXEL
# define BOTTOM_COLOR BLUE_PIXEL
# define BORDERS_COLOR 0x1080FF
# define COLOR_MAX 130 // 130
# define COLOR_MIN 30 // 30
// pi
# define M_PI 3.14159265358979323846

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		should_close;
	int		cur_img;
	t_img	img;
	t_map	map;
}			t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

typedef struct s_line
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		z0;
	int		z1;
}			t_line;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
}			t_point;

typedef struct s_iso_config
{
	int		height;
	int		z_scale;
	float	angle;
	float	vertical_angle;
	float	radian_vertical_angle;
	float	radian_angle;
}			t_iso_config;

typedef struct s_rl
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		z_increment;
	int		color_start;
	int		color_end;
	int		color_delta;
	int		color_current;
}			t_rl;

typedef struct s_colors
{
	int		red1;
	int		green1;
	int		blue1;
	int		red2;
	int		green2;
	int		blue2;
	int		interpolated_red;
	int		interpolated_green;
	int		interpolated_blue;
}			t_colors;

typedef struct s_color_management
{
	int		color;
	int		delta_z;
	int		total_steps;
	int		step;
	int		interpolated_color;
	float	interpolation_factor;
	int		initial_color;
	int		final_color;
}			t_color_management;

// pw
int			pw(t_map map);
int			render(t_data *data);
void		draw_map(t_data *data);
t_point		iso(t_data *data, t_point p);

// pw_operations
void		setup_image(t_data *data);
void		setup_hooks(t_data *data);
int			initialize_data(t_data *data, t_map map);
void		free_mlx_stuff(t_data *data);

// handle_functions
int			handle_keypress(int keysym, t_data *data);
int			handle_close(t_data *data);

// render funtions
void		render_background(t_img *img, int color);
void		render_p_line(t_data *data, t_line line);
void		render_line(t_data *data, t_line line);
int			calc_up_color(t_data *data, int z);
int			calc_down_color(t_data *data, int z);
int			max(int a, int b);

// mlx_utils
void		img_pix_put(t_img *img, int x, int y, int color);
int			ft_rgb_to_int(int red, int green, int blue);

// line tests
int			line_1(t_data *data);
int			line_2(t_data *data);
int			line_3(t_data *data);
int			line_4(t_data *data);
void		draw_area(t_data *data, t_rect sqr);

/* *********************************** */
/*                                     */
/*                 END                 */
/*                                     */
/* *********************************** */

#endif
