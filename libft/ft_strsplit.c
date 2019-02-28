/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:45:38 by cseguier          #+#    #+#             */
/*   Updated: 2018/12/05 13:56:18 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nstr(char const *str, char c)
{
	int	nb;
	int	res;
	int	i;

	res = 0;
	i = 0;
	nb = 1;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
		{
			i++;
			nb++;
		}
		while (str[i] != '\0' && str[i] != c)
		{
			i++;
			if (nb)
			{
				res++;
				nb = 0;
			}
		}
	}
	return (res);
}

static char	**ft_loop(char **tab, char *str, int j, char c)
{
	int	ccmot;
	int	x;
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ccmot = 0;
		while (str[i] != '\0' && str[i] == c)
			i++;
		while (str[i] != '\0' && str[i] != c)
		{
			i++;
			ccmot++;
		}
		if (ccmot && !(tab[j] = (char*)ft_memalloc(sizeof(char) * (ccmot))))
			return (NULL);
		x = -1;
		while (ccmot > ++x)
			tab[j][x] = str[i - ccmot + x];
		if (ccmot && ++j > 0)
			tab[j - 1][x] = '\0';
		tab[j] = 0;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	int		j;
	char	**tab;

	j = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (ft_nstr(s, c) + 1))))
		return (NULL);
	if (!(tab = ft_loop(tab, (char*)s, j, c)))
		return (NULL);
	return (tab);
}
