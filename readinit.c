/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:40:58 by arunte            #+#    #+#             */
/*   Updated: 2019/04/24 17:41:41 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_img		init_img(void *mlx, int width, int height)
{
	t_img	img;

	img.width = width;
	img.height = height;
	img.img_ptr = mlx_new_image(mlx, img.width, img.height);
	if (!img.img_ptr)
	{
		img.data = NULL;
		return (img);
	}
	img.data = (unsigned int *)mlx_get_data_addr(img.img_ptr,
												&img.bits_per_pixel,
												&img.size_line,
												&img.end);
	return (img);
}

void		final_read(char *line, int fd, t_map *map)
{
	int i;

	i = 0;
	map->tmp = (char ***)malloc(sizeof(char **) * map->height);
	while ((get_next_line(fd, &line) > 0))
	{
		map->tmp[i] = ft_strsplit(line, ' ');
		i++;
	}
}

void		map_zoom(t_map *map)
{
	if (map->height > map->width)
	{
		map->zoom = (SIZE_Y - 700) / map->height;
	}
	else
		map->zoom = (SIZE_X - 700) / map->width;
}

int			first_read_map(char *line, int fd, t_map *map)
{
	while ((get_next_line(fd, &line) > 0))
	{
		map->width = (int)ft_words_n(line, ' ');
		map->height++;
	}
	map_zoom(map);
	return (1);
}

void		init_map_content(t_map *map)
{
	int i;

	i = 0;
	map->matrix = (t_pixel *)malloc(map->width * map->height * sizeof(t_pixel));
	while (i < map->width * map->height)
	{
		map->matrix[i].x = i % map->width;
		map->matrix[i].y = i / map->width;
		map->matrix[i].z = ft_atoi(map->tmp[i / map->width][i % map->width])
			* map->zoom;
		map->matrix[i].color = 0x00bfff;
		i++;
	}
}
