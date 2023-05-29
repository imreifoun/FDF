/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 21:00:36 by areifoun          #+#    #+#             */
/*   Updated: 2023/03/31 18:27:19 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fix_screen(t_mini *back, t_data *data)
{
	if (data->y >= 100)
		data->zoom = 2;
	else if (data->y == 100)
		data->zoom = 2;
	else if (data->y < 100)
		data->zoom = 10;
	back->x = back->x * data->zoom;
	back->x1 = back->x1 * data->zoom;
	back->y = back->y * data->zoom;
	back->y1 = back->y1 * data->zoom;
	back->x += (WIDTH - data->x) / 2;
	back->y += (HIGHT - data->y) / 2;
	back->x1 += (WIDTH - data->x) / 2;
	back->y1 += (HIGHT - data->y) / 2;
}

t_mini	setcor(float i, float j, float x, float y)
{
	t_mini	tmp;

	tmp.x = i;
	tmp.y = j;
	tmp.x1 = x;
	tmp.y1 = y;
	return (tmp);
}

void	template(t_data *back)
{
	int	i;
	int	j;

	j = 0;
	while (j < back->y)
	{
		i = 0;
		while (i < back->x)
		{
			if (i < (back->x - 1))
				bres(setcor(i, j, i + 1, j), back);
			if (j < (back->y - 1))
				bres(setcor(i, j, i, j + 1), back);
			i++;
		}
		j++;
	}
}
