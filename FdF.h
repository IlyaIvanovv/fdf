/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:10:30 by arunte            #+#    #+#             */
/*   Updated: 2019/03/31 16:27:44 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/includes/libft.h"

typedef struct s_pixel
{
	int x;
	int y;
	int z;
	unsigned int color;
}				t_pixel;

typedef struct	s_map
{
	t_pixel	*matrix;
	int		height;
	int		width;
}				t_map;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_window;

//int     map_draw(t_map *map);
