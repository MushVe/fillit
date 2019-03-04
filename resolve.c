/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:34:26 by cseguier          #+#    #+#             */
/*   Updated: 2019/03/04 13:46:26 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	translate(int ***coord, int crnt_tetrimino, int x, int y)
{
	int	i_block;

	i_block = -1;
	while (++i_block < 4)
	{
		coord[crnt_tetrimino][i_block][0] += x;
		coord[crnt_tetrimino][i_block][1] += y;
	}
}

static int	collide(int ***coord, int current)
{
	int	prev;
	int	b_cur;
	int	b_pre;

	b_cur = -1;
	while (++b_cur < 4)
	{
		prev = -1;
		while (++prev < current)
		{
			b_pre = -1;
			while (++b_pre < 4)
				if (coord[current][b_cur][0] == coord[prev][b_pre][0]
					&& coord[current][b_cur][1] == coord[prev][b_pre][1])
					return (1);
		}
	}
	return (0);
}

static int	max(int **current, int xy)
{
	int	max;
	int	i_block;

	i_block = -1;
	max = 0;
	while (++i_block < 4)
	{
		if (max < current[i_block][xy])
			max = current[i_block][xy];
	}
	return (max);
}

int			resolve(int ***crd, int crnt, int len, int y)
{
	int	x;

	x = 0;
	if (crd[crnt] == 0)
		return (1);
	while (len > (x + max(crd[crnt], 0)) && len > (y + max(crd[crnt], 1)))
	{
		translate(crd, crnt, x, y);
		if (collide(crd, crnt))
			translate(crd, crnt, -x, -y);
		else
		{
			if (resolve(crd, crnt + 1, len, 0))
				return (1);
			translate(crd, crnt, -x, -y);
		}
		if ((x + max(crd[crnt], 0)) < len - 1)
			x++;
		else
		{
			y++;
			x = 0;
		}
	}
	return (0);
}
