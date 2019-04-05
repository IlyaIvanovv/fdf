/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:07:00 by arunte            #+#    #+#             */
/*   Updated: 2019/04/01 14:28:08 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void draw_line(t_pixel dot1, t_pixel dot2, t_window *window)
{
    //t_pixel *one;
    //t_pixel *two;
	const int deltaX = abs(dot2.x - dot1.x);
	const int deltaY = abs(dot2.y - dot1.y);
	const int signX = dot1.x < dot2.x ? 1 : -1;
	const int signY = dot1.y < dot2.y ? 1 : -1;
	//
    int error = deltaX - deltaY;
	//
	mlx_pixel_put(window->mlx_ptr, window->win_ptr, dot2.x, dot2.y, 0xFF6600);
	while (dot1.x != dot2.x || dot1.y != dot2.y)
	{
		mlx_pixel_put(window->mlx_ptr, window->win_ptr, dot1.x, dot1.y, 0xFF6600);
        int error2 = error * 2;

		if (error2 > -deltaY)
		{
			error -= deltaY;
			dot1.x += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			dot1.y += signY;
		}
	}
}

/*void ft_putchar(char c)
{
	write(1, &c, 1);
}*/

int first_read_map(char *line, int fd, t_map *map)
{
    while ((get_next_line(fd, &line) > 0))
    {
        map->width = (int) ft_words_n(line, ' ');
        map->height++;
    }
	return 1;
}

void    init_map_content(t_map *map, t_window *window)
{
    int i;
    i = 0;
    map->matrix = (t_pixel *)malloc(map->width * map->height * sizeof(t_pixel));// map->pixel[i] OR map->pixel[i*map->width + j] => map->pixel.x = j  map->pixel.y = i
    while (i < map->width * map->height)
    {
        map->matrix[i].x = i % map->width * 50 + SIZE_X / 2 - map->width * 50 / 2;
        map->matrix[i].y = i / map->width * 50 + SIZE_Y / 2 - map->height * 50 / 2;
        map->matrix[i].z = 0;
        map->matrix[i].color = 0xFF6600;
        i++;
    }
    map_draw(map, window);
}

int     map_draw(t_map *map, t_window *window)
{
    int x;
    int y;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (x + 1 < map->width)
                draw_line(map->matrix[y * map->width + x], map->matrix[y * map->width + x + 1], window);
            if (y + 1 < map->height)
                draw_line(map->matrix[y * map->width + x], map->matrix[(y + 1) * map->width + x], window);
            x++;
        }
        y++;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int fd;
    char *line;
    t_map map;
    t_window window;
    line = ft_strnew(1);
    if (argc != 2)
    {
        perror("No walid file");
        exit(0);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_putstr("Error");
    if (!(first_read_map(line, fd, &map)))
    {
		ft_putstr("warning");
		close(fd);
	}
    window.mlx_ptr = mlx_init();
    window.win_ptr = mlx_new_window(window.mlx_ptr, SIZE_X, SIZE_Y, "fdf 21 school");
    // mlx_key_hook(window->win_ptr, deal_key, (void *)window);
    init_map_content(&map, &window);
    mlx_loop(window.mlx_ptr);
    return (0);
}