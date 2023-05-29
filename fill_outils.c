/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:30:36 by areifoun          #+#    #+#             */
/*   Updated: 2023/03/30 00:38:52 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_hex(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '0' && string[i + 1] == 'x')
			return (1);
		i++;
	}
	return (0);
}

char	*get_hex(char *string)
{
	int	i;

	i = 0;
	while (string[i] != 'x' && string[i])
		i++;
	i++;
	return (string + i);
}

int	convert_hex(char *hex)
{
	int	decimal;
	int	hex_length;
	int	i;
	int	digit;

	decimal = 0;
	hex = get_hex(hex);
	hex_length = ft_strlen(hex);
	i = 0;
	while (i < hex_length)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
				digit = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
				digit = hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
				digit = hex[i] - 'A' + 10;
		else
			return (-1);
		decimal += digit * pow(16, hex_length - i - 1);
		i++;
	}
	return (decimal);
}

int	ft_put_z(char *string)
{
	int	i;

	i = 0;
	while (string[i] != ',' && string[i])
		i++;
	return (i);
}

int	ft_num(char *string)
{
	int		i;
	char	*p;
	int		num;
	int		x;

	i = 0;
	x = ft_put_z(string);
	p = malloc(sizeof(char) * i);
	if (!p)
		return (0);
	while (i < x)
	{
		p[i] = string[i];
		i++;
	}
	p[i] = '\0';
	num = atoi(p);
	free(p);
	return (num);
}
