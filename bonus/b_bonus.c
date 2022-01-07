/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_bonus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:23:57 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 21:16:05 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_so_long.h"

void	ft_endgame(t_map *map, char *s)
{
	map->count++;
	printf("%s ", s);
	printf("Nombre de coups = %i\n", map->count);
	close_window(map);
}
