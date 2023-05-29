/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:43:51 by areifoun          #+#    #+#             */
/*   Updated: 2023/04/07 22:30:05 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h> 
# include "libft/libft.h"

# define WIDTH 1920
# define HIGHT 1500

typedef struct s_data
{
	void	*img;
	void	*win;
	void	*mlx;
	char	*addr;
	int		bpp;
	int		ln;
	int		ed;

	float	step_by_x;
	float	step_by_y;
	int		div;

	int		x;
	int		y;
	int		**z;
	int		**c;
	int		zoom;
	int		cl;
}t_data;

typedef struct s_mini{
	float	x;
	float	y;
	float	x1;
	float	y1;

}t_mini;

int		read_x(char *map);
int		read_y(char *map);
int		ft_counter(char *str, char c);
int		function(int a, int b);
int		ft_num(char *string);
int		ft_put_z(char *string);
int		convert_hex(char *hex);
int		key(int key);
int		is_hex(char *string);
char	*get_hex(char *string);
void	run(t_data *outils, char *my_map);
void	deallocate(char **tracker);
void	template(t_data *back);
void	bres(t_mini mini, t_data *data);
void	fill(t_data *outils, int fd);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	struct_free(t_data *data);
void	fix_screen(t_mini *back, t_data *data);
void	draw_bres(t_mini *back, t_data *data);
t_mini	setcor(float i, float j, float x, float y);

#endif
