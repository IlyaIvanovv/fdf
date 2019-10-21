/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arunte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:31:55 by arunte            #+#    #+#             */
/*   Updated: 2019/04/24 17:43:14 by arunte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_map		*reads(int argc, char **argv)
{
	t_map	*map;
	int		fd;
	char	*line;

	map = init();
	line = ft_strnew(1);
	if (argc != 2)
	{
		perror("No walid file");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putstr("Error");
	if (!(first_read_map(line, fd, map)))
	{
		ft_putstr("warning");
		close(fd);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putstr("Error");
	final_read(line, fd, map);
	close(fd);
	return (map);
}
