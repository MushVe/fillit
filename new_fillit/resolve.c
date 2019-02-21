/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:20:26 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/21 16:09:58 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*init(char *res, int nb)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (!(res = (char*)ft_memalloc(sizeof(char) * ((nb * 2) + 1))))
		return (0);	
	while (res[++i])
	{
		if (++j == (nb * 2))
		{
			j = 0;
			res[i] = '\n';
		}
		else
			res[i] = '.';
	}
	ft_putstr(res);
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

	ft_putendl("000");
	if (!(res = init(res, tetricpt(stock))))
		return (0);

	return (res);
}
