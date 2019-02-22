/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:22:07 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/22 15:48:40 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		will_collide(int ***coord, int current_tetri)
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

int		get_nb_tetri(int ***coord)
{
	int	nb;

	nb = 0;
	while (coord[nb] != 0)
		nb++;
	return (nb);
}

int		get_max(int **current, int xy)
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

int		resolve(int ***coord, int current, int len, int x, int y)
{
	if (coord[current] == 0)
		return (1);
	while (len > (x + get_max(coord[current], 0))
			&& len > (y + get_max(coord[current], 1)))
	{
		translate(coord, current, x, y);
		if (will_collide(coord, current))
			translate(coord, current, -x, -y);
		else
		{
			if (resolve(coord, current + 1, len, 0, 0))
				return (1);
			translate(coord, current, -x, -y);
		}
		if ((x + get_max(coord[current], 0)) < len - 1)
			x++;
		else
		{
			y++;
			x = 0;
		}
	}
	return (0);
}
