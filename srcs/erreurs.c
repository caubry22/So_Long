/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreurs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:06:44 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 18:48:55 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_wall(t_map *map)
{
	int	i;

	i = -1;
	while (map->line[++i] != '|')
	{
		if (map->line[i] != '1')
			return (0);
	}
	while (i <= (map->x + 1) * (map->y - 1))
	{
		if (map->line[i] == '|')
		{
			if (map->line[i + 1] != '1'
				|| map->line[i - 1] != '1')
				return (0);
		}
		i++;
	}
	while (map->line[i] != '|')
	{
		if (map->line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_countchar(t_map *map)
{
	int	i;

	i = 0;
	while (map->line[i])
	{
		if (map->line[i] == 'C')
			map->coll++;
		if (map->line[i] == 'E')
			map->nbexit++;
		if (map->line[i] == 'P')
			map->start++;
		i++;
	}
	return (1);
}

int	ft_badchar(t_map *map)
{
	if (map->coll < 1)
	{
		printf("Error\nIl n'y a pas de collectible.");
		return (1);
	}
	if (map->nbexit < 1)
	{
		printf("Error\nIl n'y a pas de sortie");
		return (1);
	}
	if (map->start != 1)
	{
		printf("Error\nIl n'y a pas de depart.");
		return (1);
	}
	return (0);
}

int	ft_erreurs(t_map *map)
{
	if (map->x == map->y)
	{
		printf("Error\nLa map n'est pas rectangulaire");
		return (1);
	}
	if (!ft_countchar(map))
		return (1);
	if (ft_badchar(map))
		return (1);
	if (!ft_check_wall(map))
	{
		printf("Error\nLa map n'est pas entoure de murs.");
		return (1);
	}
	printf("La map est valide\n");
	return (0);
}

int	ft_check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\nIl n'y a pas le bon nombre d'arguments.");
		return (1);
	}
	if (!ft_strber(av[1]))
	{
		printf("Error\nLa map n'est pas au bon format (.ber)");
		return (1);
	}
	return (0);
}
