/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:24:43 by areifoun          #+#    #+#             */
/*   Updated: 2023/04/07 22:35:13 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	loop_deallocate(int **clear)
{
	int	i;

	i = 0;
	while (clear[i])
	{
		free(clear[i]);
		i++;
	}
	free(clear);
}

int	mouse(t_data *data)
{
	loop_deallocate(data->z);
	loop_deallocate(data->c);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

int	key(int key)
{
	if (key == 53)
		exit(0);
	else
		return (0);
}

void	valid_coor(t_data *data, char *map)
{
	if (!data)
		exit(1);
	data->y = read_y(map);
	data->x = read_x(map);
	if (data->y == 0 && data->y == 0)
		exit(0);
	return ;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argv[1] == NULL || argc != 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	valid_coor(data, argv[1]);
	data->mlx = mlx_init();
	run(data, argv[1]);
	data->win = mlx_new_window(data->mlx, WIDTH, HIGHT, "FDF : areifoun");
	data->img = mlx_new_image(data->mlx, WIDTH, HIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->ln, &data->ed);
	template(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, key, data->img);
	mlx_hook(data->win, 17, 0L, mouse, data);
	mlx_loop(data->mlx);
	return (0);
}
