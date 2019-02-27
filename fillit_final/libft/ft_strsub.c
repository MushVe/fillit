/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 04:45:07 by czhang            #+#    #+#             */
/*   Updated: 2018/11/21 02:58:06 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (len--)
		str[i++] = *(s + start++);
	str[i] = 0;
	return (str);
}
