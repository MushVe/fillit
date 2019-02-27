/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 00:52:50 by czhang            #+#    #+#             */
/*   Updated: 2018/11/15 01:28:31 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s10;
	unsigned char	*s20;
	unsigned long	i;

	s10 = (unsigned char*)s1;
	s20 = (unsigned char*)s2;
	i = 0;
	while (i < n && s10[i] == s20[i])
		i++;
	if (i == n)
		return (0);
	return (s10[i] - s20[i]);
}
