/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keysym.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:47:28 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 18:33:39 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*ft_push_w(t_map *map, int *i, int j)
{
	if (map->tmap[*i - 1][j] == 'E')
	{
		if (map->coll == 0)
		{
			map->count++;
			printf("Gagne ! Nombre de coups = %i\n", map->count);
			close_window(map);
		}
	}
	else
	{
		map->count++;
		printf("Nombre de coup = %i\n", map->count);
		if (map->tmap[*i - 1][j] == 'C')
			map->coll--;
		map->tmap[*i][j] = '0';
		(*i)--;
		map->tmap[*i][j] = 'P';
	}
	return (map);
}

t_map	*ft_push_a(t_map *map, int i, int *j)
{
	if (map->tmap[i][*j - 1] == 'E')
	{
		if (map->coll == 0)
		{
			map->count++;
			printf("Gagne ! Nombre de coup = %i\n", map->count);
			close_window(map);
		}
	}
	else
	{
		map->count++;
		printf("Nombre de coup = %i\n", map->count);
		if (map->tmap[i][*j - 1] == 'C')
			map->coll--;
		map->tmap[i][*j] = '0';
		(*j)--;
		map->tmap[i][*j] = 'A';
	}
	return (map);
}

t_map	*ft_push_s(t_map *map, int *i, int j)
{
	if (map->tmap[*i + 1][j] == 'E')
	{
		if (map->coll == 0)
		{
			map->count++;
			printf("Gagne ! Nombre de coup = %i\n", map->count);
			close_window(map);
		}
	}
	else
	{
		map->count++;
		printf("Nombre de coup = %i\n", map->count);
		if (map->tmap[*i + 1][j] == 'C')
			map->coll--;
		map->tmap[*i][j] = '0';
		(*i)++;
		map->tmap[*i][j] = 'S';
	}
	return (map);
}

t_map	*ft_push_d(t_map *map, int i, int *j)
{
	if (map->tmap[i][*j + 1] == 'E')
	{
		if (map->coll == 0)
		{
			map->count++;
			printf("Gagne ! Nombre de coup = %i\n", map->count);
			close_window(map);
		}
	}
	else
	{
		map->count++;
		printf("Nombre de coup = %i\n", map->count);
		if (map->tmap[i][*j + 1] == 'C')
			map->coll--;
		map->tmap[i][*j] = '0';
		(*j)++;
		map->tmap[i][*j] = 'D';
	}
	return (map);
}

int	handle_input(int keysym, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->tmap[i][j] && !authorized_char("PASD", map->tmap[i][j]))
	{
		j++;
		if (!map->tmap[i][j])
		{
			i++;
			j = 0;
		}
	}
	if (keysym == XK_Escape)
		close_window(map);
	if (keysym == 'w' && map->tmap[i - 1][j] != '1')
		ft_push_w(map, &i, j);
	if (keysym == 'a' && map->tmap[i][j - 1] != '1')
		ft_push_a(map, i, &j);
	if (keysym == 's' && map->tmap[i + 1][j] != '1')
		ft_push_s(map, &i, j);
	if (keysym == 'd' && map->tmap[i][j + 1] != '1')
		ft_push_d(map, i, &j);
	return (0);
}
