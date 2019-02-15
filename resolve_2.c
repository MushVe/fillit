/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:17:21 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/15 17:04:57 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	is_occupied(int ***coord, int c_tetri, int c_block)
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
