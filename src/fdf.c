/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:08:11 by gneto-co          #+#    #+#             */
/*   Updated: 2024/02/08 20:07:30 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void print_line(char* key, char* string)
{
	ft_putstr("\n\e[0;36;40m");
	ft_putstr(key);
	ft_putstr("\033[0m : ");
	ft_putstr(string);
}

static void	print_instructions(void)
{
	ft_putstr("\n\e[0;36;40mFdf controls:\033[0m\n");
	print_line("(A)", "move image left");
	print_line("(D)", "move image right");
	print_line("(W)", "move image up");
	print_line("(S)", "move image down");
	ft_putstr("\n");
	print_line("(E)", "move speed increase");
	print_line("(Q)", "move speed decrease");
	ft_putstr("\n");
	print_line("(I)", "zoom in");
	print_line("(O)", "zoom out");
	print_line("(R)", "increase height");
	print_line("(F)", "decrease height");
	ft_putstr("\n");
	print_line("(C)", "increase color");
	print_line("(V)", "decrease color");
	print_line("(X)", "reset figure");
	ft_putstr("\n");
	print_line("(Up Arrow)", "rotate forward");
	print_line("(Down Arrow)", "rotate backward");
	print_line("(Left Arrow)", "rotate to the left");
	print_line("(Right Arrow)", "rotate to the right");
	ft_putstr("\n");
	system("sleep 2");
}

void	fdf(char* file_name)
{
	int		y_max;
	t_map	map;

	y_max = ft_filelen(file_name);
	map = get_file_coordinates(file_name, y_max);
	print_instructions();
	pw(map);
	free_matrix((map.matrix), y_max);
}
