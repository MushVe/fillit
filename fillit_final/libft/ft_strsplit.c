/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 01:53:17 by czhang            #+#    #+#             */
/*   Updated: 2018/11/21 03:05:32 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ptitfree(char **tab, int j)
{
	while (j)
		ft_strdel(&tab[j-- - 1]);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len_word;
	char	**tab;

	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_cntwrd(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		len_word = 0;
		if (s[i] && s[i] != c)
		{
			while (s[i + len_word] && s[i + len_word] != c)
				len_word++;
			if (!(tab[j++] = ft_strsub(s, i, len_word)))
				ptitfree(tab, j);
			i += len_word;
		}
	}
	tab[j] = 0;
	return (tab);
}
