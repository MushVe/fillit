/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:33:31 by czhang            #+#    #+#             */
/*   Updated: 2019/02/15 16:34:03 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	iter_coord(int ***coord, int cpt, void (*f)(int *tetri))
{
	int i;

	while (cpt--)
	{
		i = -1;
		while (++i < 4)
			f(coord[cpt][i]);
	}
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
