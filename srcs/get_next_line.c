/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:08:47 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 18:33:41 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_newtmp(char *tmp, char *new_tmp, int k)
{
	int	i;

	i = 0;
	while (tmp[k + i + 1])
	{
		new_tmp[i] = tmp[k + i + 1];
		i++;
	}
	new_tmp[i] = 0;
	return (new_tmp);
}

static char	*ft_tmp(char *tmp)
{
	int		i;
	int		k;
	char	*new_tmp;

	i = 0;
	k = 0;
	if (!tmp)
		return (NULL);
	while (tmp[k] && tmp[k] != '\n')
		k++;
	while (tmp[k + i])
		i++;
	if (i == 0)
	{
		free(tmp);
		return (NULL);
	}
	new_tmp = malloc(sizeof(char) * i + 1);
	if (!new_tmp)
		return (NULL);
	new_tmp = ft_newtmp(tmp, new_tmp, k);
	free(tmp);
	return (new_tmp);
}

char	*ft_line(char *tmp)
{
	int		i;
	char	*line;

	i = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

int	ft_free(char *tmp, int i)
{
	if (!tmp)
		return (i);
	free(tmp);
	return (i);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	char		*buf;
	static char	*tmp;

	ret = 1;
	if (fd < 0 || !line)
		return (-1);
	while (ret && !ft_stop(tmp))
	{
		buf = malloc(sizeof(char) * 1 + 1);
		if (!buf)
			return (-1);
		ret = read(fd, buf, 1);
		if (ret == -1)
			return (ft_free(buf, -1));
		buf[ret] = 0;
		tmp = ft_strjoin(tmp, buf);
		free(buf);
		buf = NULL;
	}
	*line = ft_line(tmp);
	tmp = ft_tmp(tmp);
	if (!ret)
		return (ft_free(tmp, 0));
	return (1);
}
