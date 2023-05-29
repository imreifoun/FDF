/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:51:47 by areifoun          #+#    #+#             */
/*   Updated: 2023/03/31 18:31:47 by areifoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fd_free(char *buff, char *stmp)
{
	char	*s_new;

	s_new = ft_strjoin(buff, stmp);
	free(buff);
	return (s_new);
}

char	*read_fd(char *buffer, int fd)
{
	char	*tmp;
	int		counter;

	counter = 1;
	if (!buffer)
		ft_calloc(1, 1);
	tmp = ft_calloc(2, sizeof(char));
	while (counter > 0)
	{
		counter = read(fd, tmp, 1);
		if (counter == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[counter] = 0;
		buffer = fd_free(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*return_line(char *buff)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	string = ft_calloc(i + 2, sizeof(char));
	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		string[j++] = buff[i++];
	if (buff[i] == '\0')
		string[j++] = '\0';
	else if (buff[i] == '\n')
		string[j++] = '\n';
	return (string);
}

char	*next_line(char *cleaner)
{
	char	*string;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (!cleaner[i])
	{
		free(cleaner);
		return (NULL);
	}
	while (cleaner[i] && cleaner[i] != '\n')
		i++;
	if (cleaner[i] == '\n')
		i++;
	string = ft_calloc(ft_strlen(cleaner) + 1 - i, sizeof(char));
	while (cleaner[i])
		string[x++] = cleaner[i++];
	free(cleaner);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*tracker;
	char		*line;

	line = NULL;
	if (!tracker)
		tracker = ft_strdup("");
	if (fd < 0)
		return (NULL);
	tracker = read_fd(tracker, fd);
	if (!tracker)
		return (NULL);
	line = return_line(tracker);
	tracker = next_line(tracker);
	return (line);
}
