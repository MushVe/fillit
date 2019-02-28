/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:40:14 by cseguier          #+#    #+#             */
/*   Updated: 2018/12/05 18:31:26 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	cpt;
	size_t	len;

	i = 0;
	cpt = 0;
	len = ft_strlen(src);
	while (dest[cpt] && cpt < size)
		cpt++;
	if (size > 0)
	{
		while (src[i] && cpt < size - 1)
		{
			dest[cpt++] = src[i++];
		}
	}
	if (i > 0)
	{
		dest[cpt] = '\0';
		return (len + cpt - i);
	}
	return (len + cpt);
}
