/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 07:17:42 by czhang            #+#    #+#             */
/*   Updated: 2018/11/20 20:20:52 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst0;
	const char	*src0;

	dst0 = (char*)dst;
	src0 = (const char*)src;
	while (n--)
		*dst0++ = *src0++;
	return (dst);
}
