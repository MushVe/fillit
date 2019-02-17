/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:33:31 by czhang            #+#    #+#             */
/*   Updated: 2019/02/15 20:56:07 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		iter_coord(int ***coord, void (*f)(int *tetri))
{
	int	i_tetri;
	int	i_block;

	i_tetri = -1;
	while (coord[++i_tetri] != 0)
	{
		i_block = -1;
		while (++i_block < 4)
			f(coord[i_tetri][i_block]);
	}
}

static void	translate_right(int **block, int plus_x)
{
	int i_block;

	i_block = -1;
	while (++i_block < 4)
		block[i_block][0] += plus_x;
}

static void	translate_down(int **block, int plus_y)
{
	int i_block;

	i_block = -1;
	while (++i_block < 4)
		block[i_block][1] += plus_y;
}

void		translate(int ***coord, int current_tetrimino, int plus_x, int plus_y)
{
	translate_right(coord[current_tetrimino], plus_x);
	translate_down(coord[current_tetrimino], plus_y);
}

/*
   void	int_iter_coord(int ***coord, int cpt, int (*f)(int *tetri))
   {
   int i;

   while (cpt--)
   {
   i = -1;
   while (++i < 4)
   f(coord[cpt][i]);
   }
   }
   */
