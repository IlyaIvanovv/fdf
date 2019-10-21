/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:03:30 by arunte            #+#    #+#             */
/*   Updated: 2019/04/24 17:42:19 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		key_press(int keys, void *param)
{
	t_map *map;

	map = (t_map *)param;
	if (keys == 53)
		exit(0);
	if (keys == 123 || keys == 124
			|| keys == 126 || keys == 125)
		moves(keys, map);
	else if (keys == 67 || keys == 75
			|| keys == 69 || keys == 78
			|| keys == 92 || keys == 91)
		rotate(keys, map);
	return (0);
}

void	controls(t_map *map)
{
	mlx_hook(map->window.win_ptr, 2, 0, key_press, map);
	mlx_hook(map->window.win_ptr, 17, 0, closes, map);
	mlx_hook(map->window.win_ptr, 4, 0, (void *)scroll, map);
}
