/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:10:30 by arunte            #+#    #+#             */
/*   Updated: 2019/03/28 19:04:59 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/includes/libft.h"
#define BUFF_SIZE 10000;


typedef struct s_pixel
{
	int x;
	int y;
}				t_dot;
typedef struct	s_dot
{
	int		x;
	int		y;
	t_dot   dot1;
}				t_pixel;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_window;
