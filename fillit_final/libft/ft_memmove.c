/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:51:46 by czhang            #+#    #+#             */
/*   Updated: 2018/11/20 23:42:53 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dst0;
	const char		*src0;

	dst0 = (char*)dst;
	src0 = (const char*)src;
	if (dst < len + src && dst > src)
		while (len--)
			dst0[len] = src0[len];
	else
		while (len--)
			*dst0++ = *src0++;
	return (dst);
}
