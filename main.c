/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:07:00 by arunte            #+#    #+#             */
/*   Updated: 2019/03/28 19:04:52 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include "FdF.h"
#include <stdlib.h>


void draw_line(t_pixel *dot1, t_pixel *dot2, t_window *window)
{
//	int x1 = sx1;
//	int x2 = ex2;
//	int y1 = sy1;
//	int y2 = ey2;
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
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int deal_key(int key, void *param)
{
	t_pixel *dot1;
	t_pixel *dot2;

	pixel = (t_pixel *)param;
	draw_line();
	draw_line(pixel->x1, pixel->y1, pixel->x3, pixel->y3, pixel);
	draw_line(pixel->x2, pixel->y2, pixel->x3, pixel->y3, pixel);
	pixel->x1 = pixel->x3;
	pixel->y1 = pixel->y3;
	pixel->x2 += 50;
	pixel->y2 = 50;
	if (key == 53)
		exit(0);
	return (0);
}

int main()
{
	t_pixel *dot1;
	t_pixel *dot2;
	t_window *window

	dot1->x = 0;
	dot1->y = 0;
	dot2->x = 0;
	dot2->y = 50;
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, 1000, 1000, "mlx 42");
	mlx_key_hook(window->win_ptr, deal_key, (void *)window);
	mlx_loop(window->mlx_ptr);
}

int *read_map(char **line, const int fd)
{
	char	*tmp;
	char	read[BUFF_SIZE + 1];
	int		ret;
	char	*map

	fd = open (text, O_RDONLY);
     
	while ((ret = read(fd, read, BUFF_SIZE)) > 0)
	{
		read[ret] = '\0';
		if (*map)
		{
			tmp = map;
			map = ft_strjoin(tmp, read);
			free(tmp);
		}
		else
			map = ft_strdup(read);
	}
	return (ft_strsplit(**map, '\n'));
}

int main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		perror("No walid file");
			exit(0);
	}
		read_map((argv[1]));
}

