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

void draw_line(t_pixel dot1, t_pixel dot2, t_map *map)
{
    int i = 0;
	const int deltaX = abs(dot2.x - dot1.x);
	const int deltaY = abs(dot2.y - dot1.y);
	const int signX = dot1.x < dot2.x ? 1 : -1;
	const int signY = dot1.y < dot2.y ? 1 : -1;
	//
    int error = deltaX - deltaY;
	//
	mlx_pixel_put(map->window.mlx_ptr, map->window.win_ptr, dot2.x, dot2.y, map->matrix->color);
	while (dot1.x != dot2.x || dot1.y != dot2.y)
	{
		mlx_pixel_put(map->window.mlx_ptr, map->window.win_ptr, dot1.x, dot1.y, map->matrix->color);
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
		i++;
	}
}

static void iso(t_map *map)
{
        int i;
        i = 0;
        double prev_z;
        double prev_y;
        int y2,z2;
        double  angle;

        while (i < map->width * map->height)
        {
            angle = (double)(map->alpha) * 3.14 / 180;
            prev_z = (double)(map->matrix[i].z);
            prev_y = (double)(map->matrix[i].y);
            y2 = (int)((prev_y * cos(angle)) + (prev_z * sin(angle)));
            z2 = -(int)((prev_y * sin(angle)) + (prev_z * cos(angle)));
            map->matrix[i].y = y2;
            map->matrix[i].z = z2;
            i++;
        }
}

int		key_press(int keycode, void *map)
{
    t_map *tmp;

    tmp = (t_map *)map;
    if (keycode == 53)
        exit(EXIT_SUCCESS);
    if (keycode == 69)
    {
        tmp->alpha += 1;
        mlx_clear_window(tmp->window.mlx_ptr, tmp->window.win_ptr);
        iso(tmp);
        map_draw(tmp);
    }
    return (0);
}

void    final_read(char *line, int fd, t_map *map)
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

int first_read_map(char *line, int fd, t_map *map)
{
    while ((get_next_line(fd, &line) > 0))
    {
        map->width = (int) ft_words_n(line, ' ');
        map->height++;
    }
	return 1;
}

void    init_map_content(t_map *map)
{
    int i;
    i = 0;
    map->matrix = (t_pixel *)malloc(map->width * map->height * sizeof(t_pixel)); // map->pixel[i] OR map->pixel[i*map->width + j] => map->pixel.x = j  map->pixel.y = i
    while (i < map->width * map->height)
    {
        map->matrix[i].x = i % map->width * 10 + SIZE_X / 2 - map->width * 20 / 2;
        map->matrix[i].y = i / map->width * 10 + SIZE_Y / 2 - map->height * 20 / 2;
        map->matrix[i].z = ft_atoi(map->tmp[i / map->width][i % map->width]) * 10;
        map->matrix[i].color = 0xFF6600;
        i++;
    }
    map->alpha = 0;
    iso(map);
    map_draw(map);
}


int     map_draw(t_map *map)
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
                draw_line(map->matrix[y * map->width + x], map->matrix[y * map->width + x + 1], map);
            if (y + 1 < map->height)
                draw_line(map->matrix[y * map->width + x], map->matrix[(y + 1) * map->width + x], map);
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
    line = ft_strnew(1);
    map.height = 0;
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
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_putstr("Error");
    final_read(line, fd, &map);
    close(fd);
    map.window.mlx_ptr = mlx_init();
    map.window.win_ptr = mlx_new_window(map.window.mlx_ptr, SIZE_X, SIZE_Y, "fdf 21 school");
    mlx_hook(map.window.win_ptr,2, 0, key_press, (void *)&map);
    init_map_content(&map);
    mlx_loop(map.window.mlx_ptr);
    return (0);
}