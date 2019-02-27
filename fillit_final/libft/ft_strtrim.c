/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 05:09:32 by czhang            #+#    #+#             */
/*   Updated: 2018/11/21 02:59:12 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int		len;
	unsigned int		i;
	unsigned int		start;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	start = 0;
	while (s[i] && ESP(s[i]))
	{
		start++;
		len--;
		i++;
	}
	if (i == len + start)
		return (ft_strnew(sizeof(char)));
	i = len + start - 1;
	while (ESP(s[i]))
	{
		i--;
		len--;
	}
	return (ft_strsub(s, start, len));
}
