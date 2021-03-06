/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:07:00 by arunte            #+#    #+#             */
/*   Updated: 2019/04/24 17:42:53 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		main(int argc, char **argv)
{
	t_map *map;

	map = reads(argc, argv);
	map->window.mlx_ptr = mlx_init();
	map->window.win_ptr = mlx_new_window(map->window.mlx_ptr, SIZE_X,
		SIZE_Y, "fdf 21 school");
	map->img = init_img(map->window.mlx_ptr, SIZE_X, SIZE_Y);
	init_map_content(map);
	project(map);
	draw_img(map->window.mlx_ptr, map->window.win_ptr, map->img);
	controls(map);
	mlx_loop(map->window.mlx_ptr);
	return (0);
}
