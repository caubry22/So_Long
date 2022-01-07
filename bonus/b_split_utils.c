/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_split_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:20:44 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 19:37:12 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_so_long.h"

int	ft_nbmot(char *s, char c)
{
	int	nbmot;

	nbmot = 0;
	while (*s)
	{
		if (*s != c)
		{
			nbmot++;
			while (*s != c && *s)
				s++;
		}
		while (*s == c && *s)
			s++;
	}
	return (nbmot);
}

char	*ft_fillsplit(char *mot, char *str, char c)
{
	int	i;

	i = 0;
	while (*str && *str != c)
	{
		mot[i] = *str;
		i++;
		str++;
	}
	mot[i] = 0;
	return (mot);
}

int	ft_lenmot(char *s, char c)
{
	int	n;

	n = 0;
	while (*s && *s != c)
	{
		n++;
		s++;
	}
	return (n);
}

char	**ft_split_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
