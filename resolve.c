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

static void	translate(int ***coord, int crnt, int x, int y)
{
	int	ib;

	ib = -1;
	while (++ib < 4)
	{
		coord[crnt][ib][0] += x;
		coord[crnt][ib][1] += y;
	}
}

static void	set_to_empty(int ***coord, int crnt, int len, int *is_empty, int empty)
{
	int	ib;

	ib = -1;
	while (++ib < 4)
	{
		if (empty)
			is_empty[coord[crnt][ib][0] + coord[crnt][ib][1] * len] = 1;
		else
			is_empty[coord[crnt][ib][0] + coord[crnt][ib][1] * len] = 0;
	}
}

static int	will_collide(int ***coord, int current_tetri)
{
	int	prev_tetri;
	int	block_newtet;
	int	block_prevtet;

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

int			max(int **current, int xy)
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

void			to_next_empty(int *is_empty, int len, int *x, int *y, int *size)
{
	int	i;
	int	max_i;

	i = *x + *y * len;
	max_i = len * len;
	while (++i < max_i) // on veut le next, donc mini ++
		if (is_empty[i] == 1 && *x < size[0] && *y < size[1])
		{
			*x = i % len;
			*y = i / len;
			return ;
		}
	*x = len;
}

int			resolve(int ***crd, int crnt, int len, int y, int *is_empty)
{
	int	x;
	int	size[2];

	x = 0;
	if (crd[crnt] == 0)
		return (1);
	size[0] = len - max(crd[crnt], 0);
	size[1] = len - max(crd[crnt], 1);
	while (x < size[0] && y < size[1])
	{
		translate(crd, crnt, x, y);
		if (will_collide(crd, crnt))
			translate(crd, crnt, -x, -y);
		else
		{
			set_to_empty(crd, crnt, len, is_empty, 0);

			if (resolve(crd, crnt + 1, len, 0, is_empty))
				return (1);
			translate(crd, crnt, -x, -y);
			set_to_empty(crd, crnt, len, is_empty, 1);
		}
		to_next_empty(is_empty, len, &x, &y, size);
	}
	return (0);
}
