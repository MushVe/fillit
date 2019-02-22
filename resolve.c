/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:22:07 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/22 15:31:59 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Pour comprendre cette fonction il faut se representer
 * les differentes valeurs sur un dessin du carre avec frame
 */

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

/*
 * Si le contour (en largeur) est plus petit que la longueur du carre,
 * et si tous les blocks du tetrimino seront sur des cases vides,
 * alors on essaie des combinaisons de deplacements
 */

int		is_occupied(int ***coord, int c_tetri, int c_block)
{
	int	i_tetri;
	int	i_block;

	i_tetri = -1;
	while (++i_tetri < c_tetri)
	{
		i_block = -1;
		while (++i_block < 4)
			if (coord[i_tetri][i_block][0] == coord[c_tetri][c_block][0]
					&& coord[i_tetri][i_block][1] == coord[c_tetri][c_block][1])
				return (1);
	}
	return (0);
}

void	ft_test(char *str, int i)
{
	ft_putstr(str);
	ft_putstr(" : ");
	ft_putnbr(i);
	ft_putendl("");
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

int		resolve(int ***coord, int current, int len)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
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
			if (resolve(coord, current + 1, len))
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
