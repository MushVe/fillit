/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 05:39:11 by czhang            #+#    #+#             */
/*   Updated: 2018/11/21 02:54:49 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char*)str;
	while (len--)
		*s++ = (unsigned char)c;
	return (str);
}
