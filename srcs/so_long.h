/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:05:16 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 19:15:20 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_map
{
	int		x;
	int		y;
	char	*line;
	char	**tmap;
	void	*mlx_ptr;
	void	*win_ptr;
	int		coll;
	int		nbexit;
	int		start;
	int		count;
	void	*wall;
	void	*back;
	void	*collectible;
	void	*exit;
	void	*player;
	void	*player1;
	void	*player2;
	void	*player3;
	int		size;
}	t_map;

typedef struct s_split
{
	char	*str;
	char	**split;
	int		mot;
	int		len;
	int		k;
}	t_split;

int			get_next_line(int fd, char **line);
char		*ft_line(char *line);
int			ft_srcsize(char *content);
char		*ft_memmove(char *dst, char *src, int k);
char		*ft_strjoin(char *s1, char *s2);
int			ft_stop(char *tmp);
int			ft_erreurs(t_map *map);
int			authorized_char(char *str, char c);
int			ft_strber(char *map);
char		**ft_split(char *s, char c);
int			render(t_map *map);
int			handle_input(int keysym, t_map *map);
int			ft_maperror(int ac, char **av, t_map *map);
t_map		*ft_initmap(t_map *map);
int			count_col(char *line);
int			ft_check_arg(int ac, char **av);
char		**ft_split_free(char **split);
int			ft_lenmot(char *s, char c);
char		*ft_fillsplit(char *mot, char *str, char c);
int			ft_nbmot(char *s, char c);
int			ft_initimg_player(t_map *map);
int			ft_initimg(t_map *map);
int			ft_freetmap(t_map *map);
int			close_window(t_map *map);

#endif
