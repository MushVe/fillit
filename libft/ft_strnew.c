/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:50:08 by cseguier          #+#    #+#             */
/*   Updated: 2018/11/28 18:01:09 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t t)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (char*)ft_memalloc(sizeof(char) * (t + 1))))
		return (NULL);
	while (i <= t)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
