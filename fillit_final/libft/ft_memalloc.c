/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 03:03:49 by czhang            #+#    #+#             */
/*   Updated: 2018/12/03 19:22:42 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*truc;

	if (!(truc = (void*)malloc(size)))
	{
		ft_memdel(&truc);
		return (NULL);
	}
	ft_bzero(truc, size);
	return (truc);
}
