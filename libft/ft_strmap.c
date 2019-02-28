/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:09:01 by cseguier          #+#    #+#             */
/*   Updated: 2018/12/05 13:51:46 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		t;
	int		i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	t = ft_strlen((char*)s);
	if (!(res = (char*)ft_memalloc(sizeof(char) * (t + 1))))
		return (0);
	while (s[i] != '\0')
	{
		res[i] = f(s[i]);
		i++;
	}
	return (res);
}
