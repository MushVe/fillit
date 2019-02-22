/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:33:31 by czhang            #+#    #+#             */
/*   Updated: 2019/02/22 15:43:39 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	translate_right(int **block, int plus_x)
{
	int	i_block;

	i_block = -1;
	while (++i_block < 4)
		block[i_block][0] += plus_x;
}

static void	translate_down(int **block, int plus_y)
{
	int	i_block;

	i_block = -1;
	while (++i_block < 4)
		block[i_block][1] += plus_y;
}

void		translate(int ***coord, int crnt_tetrimino, int plus_x, int plus_y)
{
	translate_right(coord[crnt_tetrimino], plus_x);
	translate_down(coord[crnt_tetrimino], plus_y);
}
