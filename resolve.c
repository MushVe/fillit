/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:22:07 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/15 18:33:19 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

static void translate(int ***coord, int current_tetrimino, int plus_x, int plus_y)
{
	translate_right(coord[current_tetrimino], plus_x);
	translate_down(coord[current_tetrimino], plus_y);
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

/*
 * * frame est le contour des tetriminos deja places
 */
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
		frame[1][len] = search_empty(coord, len, current_tetrimino, 1);
	}
	return (frame);
}

int     will_collide(int **tetri, int **frame, int i_line)
{
	int i_block1;
	int i_block2;

	i_block1 = -1;
	while (++i_block1 < 4)
	{
		i_block2 = -1;
		while (++i_block2 < 4)
			if(frame[0][tetri[i_block1][1] + i_line] > tetri[i_block2][1] + frame[0][i_line])
				return (1);
	}
	return (0);
}


void	lolz(int ***coord, int current_tetrimino)
{
	int i_line;
	int	**frame;
	int	len;

	frame = get_frame(coord, current_tetrimino);
	len = get_len(coord, current_tetrimino);
	i_line = -1;
	while (++i_line < len)
	{
		if (frame[0][i_line] < len &&
				!will_collide(coord[current_tetrimino], frame, i_line))
		{
			translate(coord, current_tetrimino, frame[0][i_line], i_line);
			return ;
		}
	}
}

/*
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
   */
