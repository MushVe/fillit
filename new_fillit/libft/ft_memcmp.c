/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:13:28 by cseguier          #+#    #+#             */
/*   Updated: 2018/12/05 18:39:14 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	size_t				i;
	unsigned char const	*d;
	unsigned char const	*s;

	i = 0;
	d = s1;
	s = s2;
	while (i < n)
	{
		if (d[i] != s[i])
			return ((int)(d[i] - s[i]));
		i++;
	}
	return (0);
}
