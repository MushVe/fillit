/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:22:07 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/15 21:28:04 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Pour comprendre cette fonction il faut se representer
 * les differentes valeurs sur un dessin du carre avec frame
*/

int		will_collide(int **tetri, int **frame, int i_line)
{
	int i_block1;
	int i_block2;

	i_block1 = -1;
	while (++i_block1 < 4)
	{
		i_block2 = -1;
		while (++i_block2 < 4)
			if (frame[0][tetri[i_block1][1] + i_line]
					> tetri[i_block2][1] + frame[0][i_line])
				return (1);
	}
	return (0);
}

/*
 * Si le contour (en largeur) est plus petit que la longueur du carre,
 * et si tous les blocks du tetrimino seront sur des cases vides,
 * alors on deplace
*/

void	try_translate(int ***coord, int current_tetrimino)
{
	int i_line;
	int	**frame;
	int	len;

	frame = get_frame(coord, current_tetrimino);
	len = get_len(coord, current_tetrimino);
	i_line = -1;
	while (++i_line < len)
	{
		if (frame[0][i_line] < len
			&& !will_collide(coord[current_tetrimino], frame, i_line))
		{
			translate(coord, current_tetrimino, frame[0][i_line], i_line);
			return ;
		}
	}
}

int		resolve(int ***coord, int cpt)
{
	int	finished;
	int	i_tetri;

	finished = 0;
	i_tetri = 0;
	while (!finished)
	{
		try_translate(coord, i_tetri);
		i_tetri++;
		if (i_tetri == cpt)
			finished = 1;
	}
	return (1);
}
