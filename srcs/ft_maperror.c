/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maperror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 21:06:02 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 18:43:36 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(char *tmp, t_map *map)
{
	int	i;

	i = 0;
	if (map->y == 0)
		map->x = count_col(tmp);
	else
	{
		if (count_col(tmp) != map->x)
		{
			printf("Error\nLa map n'est pas rectangulaire");
			return (1);
		}
	}
	while (tmp[i])
	{
		if (!authorized_char("10CPE", tmp[i]))
		{
			printf("Error\nLa map contient des caracteres non autorises.");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_maperror(int ac, char **av, t_map *map)
{
	char	*tmp;
	int		fd;
	int		ret;

	fd = open(av[1], O_RDONLY);
	ft_initmap(map);
	if (ft_check_arg(ac, av))
		return (1);
	ret = get_next_line(fd, &tmp);
	while (ret)
	{
		map->line = ft_strjoin(map->line, tmp);
		if (ft_check_map(tmp, map))
			return (1);
		free(tmp);
		(map->y)++;
		map->line = ft_strjoin(map->line, "|");
		ret = get_next_line(fd, &tmp);
	}
	free(tmp);
	if (ft_erreurs(map))
		return (1);
	return (0);
}
