/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:37:53 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 18:33:44 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_srcsize(char *content)
{
	int	i;

	i = 0;
	if (!content)
		return (0);
	while (content[i])
		i++;
	return (i);
}

char	*ft_memmove(char *dst, char *src, int k)
{
	int	i;

	i = 0;
	if (dst == src || !src)
		return (dst);
	while (src[i])
	{
		dst[k] = src[i];
		i++;
		k++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		s1len;
	int		s2len;
	int		jlen;

	s1len = ft_srcsize(s1);
	s2len = ft_srcsize(s2);
	jlen = 0;
	join = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!join)
		return (NULL);
	ft_memmove(join, s1, jlen);
	jlen = jlen + s1len;
	ft_memmove(join, s2, jlen);
	jlen = jlen + s2len;
	join[jlen] = 0;
	free(s1);
	return (join);
}

int	ft_stop(char *tmp)
{
	int	i;

	i = 0;
	if (!tmp)
		return (0);
	while (tmp[i] && tmp[i] != '\n')
	{
		i++;
	}
	if (!tmp[i])
		return (0);
	return (1);
}
