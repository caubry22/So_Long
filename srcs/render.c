/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:41:12 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 18:33:28 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putimg_player(t_map *map, int i, int j)
{
	if (map->tmap[i][j] == 'P')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player,
			j * map->size, i * map->size);
	if (map->tmap[i][j] == 'A')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player1,
			j * map->size, i * map->size);
	if (map->tmap[i][j] == 'S')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player2,
			j * map->size, i * map->size);
	if (map->tmap[i][j] == 'D')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->player3,
			j * map->size, i * map->size);
	return (1);
}

int	ft_putimg(t_map *map, int i, int j)
{
	if (map->tmap[i][j] == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->back,
			j * map->size, i * map->size);
	if (map->tmap[i][j] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->wall,
			j * map->size, i * map->size);
	if (map->tmap[i][j] == 'C')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->collectible,
			j * map->size, i * map->size);
	if (map->tmap[i][j] == 'E')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->exit,
			j * map->size, i * map->size);
	return (1);
}

int	ft_initimg_player(t_map *map)
{
	char	*path_p;
	char	*path_p1;
	char	*path_p2;
	char	*path_p3;

	path_p = "img/P_3.xpm";
	path_p1 = "img/P_1.xpm";
	path_p2 = "img/P_0.xpm";
	path_p3 = "img/P_2.xpm";
	if (map->win_ptr != NULL)
	{
		map->player = mlx_xpm_file_to_image(map->mlx_ptr, path_p,
				&map->size, &map->size);
		map->player1 = mlx_xpm_file_to_image(map->mlx_ptr, path_p1,
				&map->size, &map->size);
		map->player2 = mlx_xpm_file_to_image(map->mlx_ptr, path_p2,
				&map->size, &map->size);
		map->player3 = mlx_xpm_file_to_image(map->mlx_ptr, path_p3,
				&map->size, &map->size);
	}
	return (1);
}

int	ft_initimg(t_map *map)
{
	char	*path_0;
	char	*path_1;
	char	*path_c;
	char	*path_e;

	path_0 = "img/0.xpm";
	path_1 = "img/1.xpm";
	path_c = "img/C.xpm";
	path_e = "img/E.xpm";
	if (map->win_ptr != NULL)
	{
		map->wall = mlx_xpm_file_to_image(map->mlx_ptr, path_1,
				&map->size, &map->size);
		map->back = mlx_xpm_file_to_image(map->mlx_ptr, path_0,
				&map->size, &map->size);
		map->collectible = mlx_xpm_file_to_image(map->mlx_ptr, path_c,
				&map->size, &map->size);
		map->exit = mlx_xpm_file_to_image(map->mlx_ptr, path_e,
				&map->size, &map->size);
	}
	return (1);
}

int	render(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->tmap[i] && map->tmap[i][j])
	{
		ft_putimg(map, i, j);
		ft_putimg_player(map, i, j);
		j++;
		if (!map->tmap[i][j])
		{
			i++;
			j = 0;
		}
	}
	return (0);
}
