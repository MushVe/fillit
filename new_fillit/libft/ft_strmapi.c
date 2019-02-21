/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:38:05 by cseguier          #+#    #+#             */
/*   Updated: 2018/12/05 13:52:42 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
