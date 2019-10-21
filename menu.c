/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:13:44 by arunte            #+#    #+#             */
/*   Updated: 2019/04/24 17:41:23 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void		print_menu(t_map *map)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = map->window.mlx_ptr;
	win = map->window.win_ptr;
	mlx_string_put(mlx, win, 65, y += 20, 0xdd2e44, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, 0xdd2e44, "Zoom: Scroll mouse");
	mlx_string_put(mlx, win, 15, y += 30, 0xdd2e44, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, 0xdd2e44, "Rotate: Press & Move");
	mlx_string_put(mlx, win, 15, y += 30, 0xdd2e44, "Rotate:");
	mlx_string_put(mlx, win, 57, y += 25, 0xdd2e44, "X-Axis: + and -");
	mlx_string_put(mlx, win, 57, y += 25, 0xdd2e44, "Y-Axis:  / and *");
	mlx_string_put(mlx, win, 57, y += 25, 0xdd2e44, "Z-Axis:  8/9");
}
