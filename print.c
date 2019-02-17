/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:03:59 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/15 19:48:04 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*init_square(int len)
{
	char	*res;
	int		i;

	if (!(res = ft_strnew((len + 1) * len)))
		return (0);
	i = -1;
	while (++i < (len + 1) * len)
	{
		if (i % (len + 1) == len)
			res[i] = '\n';
		else
			res[i] = '.';
	}
	return (res);
}

int		print(int ***coord, int len)
{
	char	*res;
	int	i_block;
	int	i_tetri;

	if (!(res = init_square(len)))
		return (0);
	i_tetri = -1;
	while (coord[++i_tetri] != 0)
	{
		i_block = -1;
		while (++i_block < 4)
			res[coord[i_tetri][i_block][0] + coord[i_tetri][i_block][1] * (len + 1)] = 'A' + i_tetri;
	}
	ft_putstr(res);
	return (1);
}
