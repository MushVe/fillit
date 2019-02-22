/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:20:26 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/22 09:51:05 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*init(char *res, int nb)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	nb = (nb * 2) + 1;
	if (!(res = (char*)ft_memalloc(sizeof(char) * ((nb * nb) - nb))))
		return (0);
	while (++i < (nb * nb) - nb)
	{
		if (++j == nb)
		{
			j = 0;
			res[i] = '\n';
		}
		else
			res[i] = '.';
	}
	return (res);
}

static int	tetricpt(char **stock)
{
	int	res;

	res = -1;
	while (stock[++res]);
	return (res);
}

char		*resolve(char **stock)
{
	char *res;

	if (!(res = init(res, tetricpt(stock))))
		return (0);

	return (res);
}
