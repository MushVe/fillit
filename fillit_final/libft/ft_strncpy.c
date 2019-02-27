/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 02:37:27 by czhang            #+#    #+#             */
/*   Updated: 2018/11/15 02:50:48 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (len--)
	{
		if (*src)
			dst[i++] = *src++;
		else
			dst[i++] = 0;
	}
	return (dst);
}
