/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:12:48 by cseguier          #+#    #+#             */
/*   Updated: 2018/12/05 14:06:54 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*res;
	int		t1;
	int		t2;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	t1 = ft_strlen(s1);
	t2 = ft_strlen(s2);
	if (!(res = (char*)ft_memalloc(sizeof(char) * (t1 + t2 + 1))))
		return (0);
	while (i < t1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < t1 + t2)
	{
		res[i] = s2[i - t1];
		i++;
	}
	res[i] = '\0';
	return (res);
}
