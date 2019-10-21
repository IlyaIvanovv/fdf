/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:10:30 by arunte            #+#    #+#             */
/*   Updated: 2019/04/24 18:04:48 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "/usr/local/include/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include "math.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# define SIZE_X 1920
# define SIZE_Y 1080

typedef struct			s_pixel
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_pixel;

typedef struct			s_window
{
	void				*mlx_ptr;
	void				*win_ptr;
}						t_window;

typedef	struct			s_img
{
	void				*img_ptr;
	unsigned int		*data;
	int					size_line;
	int					end;
	int					bits_per_pixel;
	int					width;
	int					height;
}						t_img;

typedef struct			s_map
{
	t_pixel				*matrix;
	t_window			window;
	t_img				img;
	int					zoom;
	int					shift_x;
	int					shift_y;
	double				rot_x;
	double				rot_y;
	double				rot_z;
	int					height;
	int					width;
	char				***tmp;
}						t_map;

void					map_draw(t_map *map);
void					init_map_content(t_map *map);
void					final_read(char *line, int fd, t_map *map);
int						first_read_map(char *line, int fd, t_map *map);
int						key_press(int key, void *param);
void					controls(t_map *map);
void					project (t_map *map);
void					print_menu(t_map *map);
void					draw_line(t_pixel dot1, t_pixel dot2, t_map *map);
int						main(int argc, char **argv);
int						put_pix_img(void *f, t_pixel p, unsigned int color);
int						draw_img(void *mlx, void *win, t_img img);
void					moves(int key, t_map *map);
void					rotate(int keys, t_map *map);
int						closes(int key, void *map);
void					scroll(int keys, int x, int y, t_map *map);
t_img					init_img(void *mlx, int width, int height);
t_map					*init(void);
void					redraw(t_map *map);
t_map					*reads(int argc, char **argv);
#endif
