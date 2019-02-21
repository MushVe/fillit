/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:27:15 by cseguier          #+#    #+#             */
/*   Updated: 2018/12/05 13:58:17 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int cpt, int i, char const *s)
{
	while (s[i] != '\0')
	{
		cpt++;
		i++;
	}
	if (i != 0)
		i--;
	while (cpt >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i--;
		cpt--;
	}
	return (cpt);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		cpt;
	int		start;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	start = i;
	cpt = count(0, i, s);
	if (!(res = (char*)ft_memalloc(sizeof(char) * (cpt + 1))))
		return (NULL);
	i = 0;
	while (i < cpt)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
