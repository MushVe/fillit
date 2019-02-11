/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 00:24:38 by czhang            #+#    #+#             */
/*   Updated: 2018/11/20 23:44:50 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s0;

	s0 = (unsigned char*)s;
	while (n--)
		if (*s0++ == (unsigned char)c)
			return (s0 - 1);
	return (NULL);
}
