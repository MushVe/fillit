/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 07:30:16 by czhang            #+#    #+#             */
/*   Updated: 2018/11/21 03:44:21 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst0;
	const unsigned char	*src0;

	dst0 = (unsigned char*)dst;
	src0 = (const unsigned char*)src;
	while (n--)
	{
		*dst0 = *src0;
		if ((unsigned char)c == *src0)
			return (dst0 + 1);
		dst0++;
		src0++;
	}
	return (NULL);
}
