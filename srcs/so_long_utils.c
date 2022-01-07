/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 20:28:19 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 18:55:25 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	authorized_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (a[i] && a[i] == b[i])
		i++;
	if (!a[i] && !b[i])
		return (1);
	return (0);
}

int	ft_strber(char *map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map[i])
		i++;
	tmp = map + i - 4;
	if (ft_strcmp(tmp, ".ber"))
		return (1);
	return (0);
}

int	ft_strnstr(const char *haystack, const char *needle)
{
	int		j;
	int		k;
	char	*s;
	char	*n;

	j = 0;
	s = (char *)haystack;
	n = (char *)needle;
	while (s[j])
	{
		k = 0;
		while (n[k] == s[j + k])
		{
			if (!n[k + 1] && !s[j + k + 1])
				return (1);
			k++;
		}
		j++;
	}
	return (0);
}
