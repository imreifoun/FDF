/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:01:23 by areifoun          #+#    #+#             */
/*   Updated: 2023/04/07 23:37:13 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ln + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	function(int a, int b)
{
	if (a > 1000)
		return (a);
	else if (b > 1000)
		return (b);
	else if (a != b)
		return (0x00ff);
	return (0xffffff);
}

void	iso_m(float *x, float *y, int z_matrix, t_data *data)
{
	if (data->x >= 10 && data->x <= 20)
			z_matrix /= 6;
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z_matrix;
}

void	draw_bres(t_mini *back, t_data *data)
{
	int	j;

	j = 0;
	while (j < data->div)
	{
		my_mlx_pixel_put(data, (int)back->x, (int)back->y, data->cl);
		back->x = back->x + data->step_by_x;
		back->y = back->y + data->step_by_y;
		j++;
	}
}

void	bres(t_mini min, t_data *data)
{
	int		i;
	int		i1;
	int		a;
	int		b;

	a = (int)min.y;
	b = (int)min.x;
	i = data->z[(int)min.y][(int)min.x];
	i1 = data->z[(int)min.y1][(int)min.x1];
	data->cl = function(data->c[a][b], data->c[(int)min.y1][(int)min.x1]);
	iso_m(&min.x, &min.y, i, data);
	iso_m(&min.x1, &min.y1, i1, data);
	fix_screen(&min, data);
	data->step_by_x = min.x1 - min.x;
	data->step_by_y = min.y1 - min.y;
	data->div = fmax(fabs(data->step_by_x), fabs(data->step_by_y));
	data->step_by_x = data->step_by_x / data->div;
	data->step_by_y = data->step_by_y / data->div;
	draw_bres(&min, data);
}
