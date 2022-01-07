/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:41:20 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 18:33:36 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_col(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		i++;
	}
	return (i);
}

t_map	*ft_initmap(t_map *map)
{
	map->line = NULL;
	map->y = 0;
	map->coll = 0;
	map->nbexit = 0;
	map->start = 0;
	map->count = 0;
	return (map);
}

int	ft_freetmap(t_map *map)
{
	int	i;

	i = 0;
	while (map->tmap[i])
	{
		free(map->tmap[i]);
		i++;
	}
	free(map->tmap);
	return (1);
}

int	close_window(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->wall);
	mlx_destroy_image(map->mlx_ptr, map->back);
	mlx_destroy_image(map->mlx_ptr, map->collectible);
	mlx_destroy_image(map->mlx_ptr, map->exit);
	mlx_destroy_image(map->mlx_ptr, map->player);
	mlx_destroy_image(map->mlx_ptr, map->player1);
	mlx_destroy_image(map->mlx_ptr, map->player2);
	mlx_destroy_image(map->mlx_ptr, map->player3);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	ft_freetmap(map);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	exit(1);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ft_maperror(ac, av, &map))
		return (0);
	map.tmap = ft_split(map.line, '|');
	free(map.line);
	map.mlx_ptr = mlx_init();
	if (map.mlx_ptr == NULL)
		return (1);
	map.win_ptr = mlx_new_window(map.mlx_ptr,
			(map.x) * 32, (map.y) * 32, "So Long");
	if (map.win_ptr == NULL)
	{
		free(map.win_ptr);
		return (1);
	}
	ft_initimg(&map);
	ft_initimg_player(&map);
	mlx_loop_hook(map.mlx_ptr, &render, &map);
	mlx_hook(map.win_ptr, KeyPress, KeyPressMask, &handle_input, &map);
	mlx_hook(map.win_ptr, DestroyNotify,
		StructureNotifyMask, &close_window, &map);
	mlx_loop(map.mlx_ptr);
	free(map.mlx_ptr);
	return (0);
}
