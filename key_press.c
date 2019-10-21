/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:42:23 by arunte            #+#    #+#             */
/*   Updated: 2019/04/24 17:41:09 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int			closes(int key, void *map)
{
	(void)map;
	if (key == 53)
		exit(0);
	return (0);
}

void		rotate(int keys, t_map *map)
{
	if (keys == 67)
		map->rot_y += 0.05;
	else if (keys == 75)
		map->rot_y -= 0.05;
	else if (keys == 69)
		map->rot_x += 0.05;
	else if (keys == 78)
		map->rot_x -= 0.05;
	else if (keys == 92)
		map->rot_z += 0.05;
	else if (keys == 91)
		map->rot_z -= 0.05;
	redraw(map);
}

void		moves(int keys, t_map *map)
{
	if (keys == 124)
		map->shift_x += 10;
	else if (keys == 123)
		map->shift_x -= 10;
	else if (keys == 126)
		map->shift_y -= 10;
	if (keys == 125)
		map->shift_y += 10;
	redraw(map);
}

void		scroll(int keys, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	mlx_destroy_image(map->window.mlx_ptr, map->img.img_ptr);
	if (keys == 4)
	{
		if ((map->zoom) < 900)
		{
			map->zoom *= 1.5;
		}
	}
	if (keys == 5)
	{
		if ((map->zoom) > 5.0)
		{
			map->zoom *= 0.5;
		}
	}
	redraw(map);
}
