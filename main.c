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

/*void draw_line(t_pixel *dot1, t_pixel *dot2, t_window *window)
{
	const int deltaX = abs(dot2->x - dot1->x);
	const int deltaY = abs(dot2->y - dot1->y);
	const int signX = dot1->x < dot2->x ? 1 : -1;
	const int signY = dot1->y < dot2->y ? 1 : -1;
	//
    int error = deltaX - deltaY;
	//
	mlx_pixel_put(window->mlx_ptr, window->win_ptr, dot2->x, dot2->y, 0xFFFFFF);
	while (dot1->x != dot2->x || dot1->y != dot2->y)
	{
		mlx_pixel_put(window->mlx_ptr, window->win_ptr, dot1->x, dot1->y, 0xFFFFFF);
        int error2 = error * 2;

		if (error2 > -deltaY)
		{
			error -= deltaY;
			dot1->x += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			dot1->y += signY;
		}
	}
}*/

/*void ft_putchar(char c)
{
	write(1, &c, 1);
}*/

//int deal_key(int key, void *param)
//{
//	t_pixel *dot1;

	///pixel = (t_pixel *)param;
//	if (key == 53)
//		exit(0);
//	return (0);
//}

//int *read_map(char **line, int fd, t_map *map)
//{
//	char	**tmp;
//	int		i;
//	int		j;
//
//	i = 0;
//	j = 0;
//	while ((get_next_line(fd, &line) > 0))
//		{
//			/*if (!(tmp = ft_strsplit(line, ' ')))
//	        	return (NULL);
//			while (tmp[i])
//				i++;
//			//*tmp = (t_map)malloc(sizeof(t_map) * i + 1);*/
//    	}
//}

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
    map->matrix = malloc(map->width * map->height * sizeof(t_pixel));// map->pixel[i] OR map->pixel[i*map->width + j] => map->pixel.x = j  map->pixel.y = i
}

int main(int argc, char **argv)
{
    int fd;
    char *line;
    t_map map;
    line = ft_strnew(1);
    if (argc != 2) {
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
    init_map_content(&map);
    return (0);
}
              
/*
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, 1000, 1000, "mlx 42");
	mlx_key_hook(window->win_ptr, deal_key, (void *)window);
	mlx_loop(window->mlx_ptr);
}
*/
