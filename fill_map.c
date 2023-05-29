/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:59:17 by areifoun          #+#    #+#             */
/*   Updated: 2023/04/07 21:57:06 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deallocate(char **tracker)
{
	int	i;

	i = 0;
	while (tracker[i])
	{
		free(tracker[i]);
		i++;
	}
	free(tracker);
}

void	auto_fill(int i, int k, t_data *outils, char **track)
{
	while (k < outils->x && track[k])
	{
		if ((is_hex(track[k])) == 1)
		{
			outils->c[i][k] = convert_hex(track[k]);
			outils->z[i][k] = ft_num(track[k]);
		}
		else if ((is_hex(track[k])) == 0)
		{
			outils->c[i][k] = ft_atoi(track[k]);
			outils->z[i][k] = ft_atoi(track[k]);
		}
		else
			return ;
		k++;
	}
}

void	fill(t_data *outils, int fd)
{
	char	**track;
	char	*line;
	int		i;
	int		k;

	i = 0;
	while (i < outils->y)
	{
		line = get_next_line(fd);
		track = ft_split(line, ' ');
		if (!track || !line)
		{
			free(line);
			free(outils);
			exit(1);
		}
		k = 0;
		auto_fill(i, k, outils, track);
		deallocate(track);
		free(line);
		i++;
	}
	return ;
}

void	struct_free(t_data *data)
{
	free(data);
	exit(1);
}

void	run(t_data *outils, char *my_map)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(my_map, O_RDONLY, 0777);
	if (fd <= -1)
		exit(1);
	outils->z = (int **)malloc(sizeof(int *) * (outils->y + 1));
	outils->c = (int **)malloc(sizeof(int *) * (outils->y + 1));
	if (!outils->z || !outils->c)
		struct_free(outils);
	while (i < outils->y)
	{
		outils->z[i] = malloc(sizeof(int) * outils->x);
		outils->c[i] = malloc(sizeof(int) * outils->x);
		if (!outils->z || !outils->c)
			struct_free(outils);
		i++;
	}
	outils->z[i] = NULL;
	outils->c[i] = NULL;
	fill(outils, fd);
	close(fd);
	return ;
}
