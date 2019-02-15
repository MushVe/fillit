/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:03:59 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/15 18:02:22 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print(int ***coord, int len, int last_tetrimino)
{
	char	*res;
	int		nb;
	int		id;
	int x;
	int y;
	int i;

	if (!(res = (char*)ft_memalloc(sizeof(char) * (len * len) + 1)))
		return (0);
	nb = 0;
	i = -1;
	x = -1;
	y = 0;
	id = 0;
	while (++i < (len * len) + 1)
	{
		if (i == len)
			res[i] = '\n';
		res[i] = '.';
	}
	while ((++i < (len * len) + 1) && (id < last_tetrimino))
	{
		++x;
		if ((coord[id][nb][0] == x) && (coord[id][nb][1] == y))
		{
			res[i] = 'A' + id;
			if (++nb == 4)
			{
				i = 0;
				nb = 0;
				id++;
			}
		}
		if (res[i] == '\n')
		{
			x = -1;
			y++;
		}
	}
	ft_putendl(res);
	return (1);
}
