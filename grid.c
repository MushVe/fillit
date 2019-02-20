/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:25:54 by czhang            #+#    #+#             */
/*   Updated: 2019/02/20 18:31:41 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	search_empty(int ***coord, int col, int current_tetrimino, int xy)
{
	int i_tetrimino;
	int empty;
	int i_block;

	i_tetrimino = -1;
	empty = 0;
	while (++i_tetrimino < current_tetrimino)
	{
		i_block = -1;
		while (++i_block < 4)
			if (coord[i_tetrimino][i_block][!xy] == col
				&& coord[i_tetrimino][i_block][xy] > empty)
				empty = coord[i_tetrimino][i_block][xy];
	}
	return (empty);
}

/*
**	len = longueur du carre
*/

int	get_len(int ***coord, int current_tetrimino)
{
	int i_tetri;
	int i_block;
	int max;

	i_tetri = -1;
	max = 0;
	while (++i_tetri < current_tetrimino)
	{
		i_block = -1;
		while (++i_block < 4)
		{
			if (coord[i_tetri][i_block][0] > max)
				max = coord[i_tetri][i_block][0];
			if (coord[i_tetri][i_block][1] > max)
				max = coord[i_tetri][i_block][1];
		}
	}
	return (max + 1);
}

/*
**	Frame est le contour des tetriminos deja places
*/

int	**get_frame(int ***coord, int current_tetrimino)
{
	int **frame;
	int i;
	int len;

	ft_test("curr_tetr", current_tetrimino);
	len = get_len(coord, current_tetrimino);
	if (!(frame = (int**)ft_memalloc(sizeof(int*) * 2)))
		return (0);
	if (!(frame[0] = (int*)ft_memalloc(sizeof(int) * len)))
		return (0);
	if (!(frame[1] = (int*)ft_memalloc(sizeof(int) * len)))
		return (0);
	ft_test("len", len);
	while (len >= 0)
	{
		frame[0][len] = search_empty(coord, len, current_tetrimino, 0);
		frame[1][len] = search_empty(coord, len, current_tetrimino, 1);
		ft_test("frame[0][len]", frame[0][len]);
		ft_test("frame[1][len]", frame[1][len]);
		len--;
	}
	return (frame);
}
