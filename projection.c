/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:04:51 by arunte            #+#    #+#             */
/*   Updated: 2019/04/24 17:42:01 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static void		x_coord(int *y, int *z, double rot_x)
{
	int		prev_y;
	int		prev_z;

	prev_y = *y;
	prev_z = *z;
	*y = (int)((prev_y * cos(rot_x)) + prev_z * sin(rot_x));
	*z = (int)((-prev_y * sin(rot_x)) + prev_z * cos(rot_x));
}

static void		y_coord(int *x, int *z, double rot_y)
{
	int prev_x;
	int prev_z;

	prev_x = *x;
	prev_z = *z;
	*x = (int)((prev_x * cos(rot_y)) + prev_z * sin(rot_y));
	*z = (int)((-prev_x * sin(rot_y)) + prev_z * cos(rot_y));
}

static void		z_coord(int *x, int *y, double rot_z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (int)((prev_x * cos(rot_z)) - prev_y * sin(rot_z));
	*y = (int)((prev_x * sin(rot_z)) + prev_y * cos(rot_z));
}

static void		iso(int *x, int *y, int z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (int)((prev_x - prev_y) * cos(0.523599));
	*y = (int)((prev_x + prev_y) * sin(0.523599) - z);
}

void			project(t_map *map)
{
	int i;

	i = 0;
	while (i < map->width * map->height)
	{
		map->matrix[i].x = i % map->width;
		map->matrix[i].y = i / map->width;
		map->matrix[i].x *= map->zoom;
		map->matrix[i].y *= map->zoom;
		map->matrix[i].x -= map->width * map->zoom / 2;
		map->matrix[i].y -= map->height * map->zoom / 2;
		x_coord(&map->matrix[i].y, &map->matrix[i].z, map->rot_x);
		y_coord(&map->matrix[i].x, &map->matrix[i].z, map->rot_y);
		z_coord(&map->matrix[i].x, &map->matrix[i].y, map->rot_z);
		iso(&map->matrix[i].x, &map->matrix[i].y, map->matrix[i].z);
		map->matrix[i].x += map->shift_x;
		map->matrix[i].y += map->shift_y;
		map->matrix[i].x += SIZE_X / 2;
		map->matrix[i].y += SIZE_Y / 2;
		map->matrix[i].z = ft_atoi(map->tmp[i / map->width][i % map->width])
			* map->zoom;
		i++;
	}
	map_draw(map);
}
