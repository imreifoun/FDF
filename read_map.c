/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:22:34 by areifoun          #+#    #+#             */
/*   Updated: 2023/04/07 22:30:25 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_y(char *map)
{
	char		*line;
	int			fd;
	int			y_height;

	y_height = 0;
	fd = open(map, O_RDONLY, 0);
	if (fd <= -1)
		exit(1);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		y_height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (y_height);
}

int	read_x(char *map)
{
	char	*line;
	int		x_width;
	int		fd;

	x_width = 0;
	fd = open(map, O_RDONLY, 0);
	if (fd <= -1)
		exit(1);
	line = get_next_line(fd);
	if (!line)
		exit(1);
	x_width = ft_counter(line, ' ');
	free(line);
	close(fd);
	return (x_width);
}
