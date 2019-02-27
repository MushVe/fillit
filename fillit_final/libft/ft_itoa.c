/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:02:50 by czhang            #+#    #+#             */
/*   Updated: 2018/11/20 05:22:29 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	powdix(int len)
{
	long	m;

	m = 1;
	while (len--)
		m *= 10;
	return (m);
}

static int	nlen(int n)
{
	int len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	int		i;
	long	vrain;
	char	*str;

	len = (n <= 0) ? 1 : 0;
	vrain = (long)n;
	len += nlen(n);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	i = 0;
	if (vrain < 0)
	{
		str[i++] = '-';
		len--;
		vrain *= -1;
	}
	while (len--)
	{
		str[i++] = vrain / powdix(len) + '0';
		vrain = vrain - (vrain / powdix(len)) * powdix(len);
	}
	return (str);
}
