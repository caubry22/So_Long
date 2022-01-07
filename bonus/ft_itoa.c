/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caubry <caubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:49:01 by caubry            #+#    #+#             */
/*   Updated: 2021/12/20 21:15:55 by caubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_so_long.h"

int	ft_lenchar(int n, int len)
{
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_conv(char *nbr, int i, int k)
{
	if (i >= 10)
		ft_conv(nbr, i / 10, k - 1);
	nbr[k] = i % 10 + '0';
	return (nbr);
}

char	*ft_itoa(int n)
{
	int				len;
	int				k;
	char			*nbr;

	len = 1;
	len = ft_lenchar(n, len);
	k = len - 1;
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr = ft_conv(nbr, n, k);
	nbr[len] = 0;
	return (nbr);
}
