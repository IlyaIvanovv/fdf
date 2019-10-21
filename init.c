/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:20:03 by arunte            #+#    #+#             */
/*   Updated: 2019/04/24 17:42:35 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_map		*init(void)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
	{
		perror("No walid file");
		exit(0);
	}
	map->width = 0;
	map->height = 0;
	map->zoom = 1;
	map->shift_y = 0;
	map->shift_x = 0;
	map->rot_x = 0;
	map->rot_y = 0;
	map->rot_z = 0;
	return (map);
}
