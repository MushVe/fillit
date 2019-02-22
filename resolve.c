/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:22:07 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/22 18:17:33 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	translate(int ***coord, int crnt_tetrimino, int x, int y)
{
	int i_block;

	i_block = -1;
	while (++i_block < 4)
	{
		coord[crnt_tetrimino][i_block][0] += x;
		coord[crnt_tetrimino][i_block][1] += y;
	}
}

static int	will_collide(int ***coord, int current_tetri)
{
	int	prev_tetri;
	int block_newtet;
	int block_prevtet;

	block_newtet = -1;
	while (++block_newtet < 4)
	{
		prev_tetri = -1;
		while (++prev_tetri < current_tetri)
		{
			block_prevtet = -1;
			while (++block_prevtet < 4)
				if (coord[current_tetri][block_newtet][0]
						== coord[prev_tetri][block_prevtet][0]
						&& coord[current_tetri][block_newtet][1]
						== coord[prev_tetri][block_prevtet][1])
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
		if (will_collide(crd, crnt))
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
