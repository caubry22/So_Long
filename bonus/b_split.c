/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:20:38 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 19:37:16 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_so_long.h"

char	**ft_split(char *s, char c)
{
	t_split	split;
	char	**splitf;

	split.str = (char *)s;
	if (!split.str)
		return (NULL);
	split.mot = ft_nbmot(split.str, c);
	split.k = 0;
	splitf = (char **)malloc(sizeof(char *) * (split.mot + 1));
	if (!splitf)
		return (NULL);
	while (*(split.str) && split.k < split.mot)
	{
		while (*(split.str) == c && *(split.str))
			(split.str)++;
		split.len = ft_lenmot(split.str, c);
		splitf[split.k] = (char *)malloc(sizeof(char) * (split.len + 1));
		if (!splitf)
			return (ft_split_free(splitf));
		splitf[split.k] = ft_fillsplit(splitf[split.k], split.str, c);
		split.str = split.str + split.len;
		(split.k)++;
	}
	splitf[split.k] = NULL;
	return (splitf);
}
