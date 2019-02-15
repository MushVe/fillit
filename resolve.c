/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:22:07 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/15 17:04:43 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	translate_right(int **block)
{
	int i_block;

	i_block = -1;
	while (++i_block < 4)
		block[i_block][0]++;
}

static void	translate_down(int **block)
{
	int i_block;

	i_block = -1;
	while (++i_block < 4)
		block[i_block][1]++;
}

int	search_empty(int ***coord, int col, int current_tetrimino, int xy)
{
	int	i_tetrimino;
	int	empty;
	int	i_block;

	i_tetrimino = -1;
	empty = 0;
	while (++i_tetrimino < current_tetrimino)
	{
		i_block = -1;
		while (++i_block < 4)
		if (coord[i_tetrimino][i_block][!xy] == col &&
				coord[i_tetrimino][i_block][xy] > empty)
			empty = coord[i_tetrimino][i_block][xy];
	}
	return (empty + 1);
}

int			

int			get_len(int ***coord, int current_tetrimino)
{
	int	i_tetri;
	int	i_block;
	int	max;

	i_tetri = -1;
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

int			**get_frame(int ***coord, int current_tetrimino)
{
	int	**frame;
	int	i;
	int	len;

	len = get_len(coord, current_tetrimino);
	if (!(frame = (int**)ft_memalloc(sizeof(int*) * 2)))
		return (0);
	if (!(frame[0] = (int*)ft_memalloc(sizeof(int) * len)))
		return (0);
	if (!(frame[1] = (int*)ft_memalloc(sizeof(int) * len)))
		return (0);
	while (len--)
	{
		frame[0][len] = search_empty(coord, len, current_tetrimino, 0);
		frame[0][len] = search_empty(coord, len, current_tetrimino, 1);
	}
	return (frame);
}

static int	rec(int ***coord, int current_tetrimino)
{
//	coord[i_tertimino][i_block][xy];
	int	i_tetrimino;
	int	max_x;
	int	max_y;

	i_tetrimino = 0;
	max_x = 0;
	max_y = 0;
	



}

int		resolve(int ***coord)
{
	int finished;
	int	i_tetri;
	int	i_block;

	finished = 0;
	while (!finished)
	{
		rec(coord, );
		finished = coord[i][j][0] + coord[i][j][1] - 3049;
	}
	return (1);
}
