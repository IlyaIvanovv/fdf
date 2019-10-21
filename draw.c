/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:06:15 by arunte            #+#    #+#             */
/*   Updated: 2019/04/24 17:58:27 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void				redraw(t_map *map)
{
	map->img = init_img(map->window.mlx_ptr, SIZE_X, SIZE_Y);
	project(map);
	draw_img(map->window.mlx_ptr, map->window.win_ptr, map->img);
	print_menu(map);
}

int					draw_img(void *mlx, void *win, t_img img)
{
	return (mlx_put_image_to_window(mlx, win, img.img_ptr, 0, 0));
}

int					put_pix_img(void *f, t_pixel p, unsigned int color)
{
	t_map			*map;

	map = (t_map *)f;
	p.color = color;
	if ((p.y < map->img.height) && (p.y > 0) &&
			(p.x < map->img.width) && (p.x > 0))
		map->img.data[(int)p.y * map->img.width + (int)p.x] = color;
	return (1);
}

void			draw_line(t_pixel dot1, t_pixel dot2, t_map *map)
{
	t_pixel			delta;
	t_pixel			sign;
	t_pixel			cur;
	int				error[2];

	delta.x = abs(dot2.x - dot1.x);
	delta.y = abs(dot2.y - dot1.y);
	sign.x = dot1.x < dot2.x ? 1 : -1;
	sign.y = dot1.y < dot2.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = dot1;
	while (cur.x != dot2.x || cur.y != dot2.y)
	{
		put_pix_img(map, cur, map->matrix->color);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void				map_draw(t_map *map)
{
	int				x;
	int				y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x + 1 < map->width)
				draw_line(map->matrix[y * map->width + x],
						map->matrix[y * map->width + x + 1], map);
			if (y + 1 < map->height)
				draw_line(map->matrix[y * map->width + x],
						map->matrix[(y + 1) * map->width + x], map);
			x++;
		}
		y++;
	}
}
