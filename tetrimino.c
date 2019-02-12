/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:26:50 by czhang            #+#    #+#             */
/*   Updated: 2019/02/12 20:39:56 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

tetrimino	*new_tetrimino(int **coord)
{
	tetrimino	*tetri;
	int			i;

	if (!(tetri = (tetrimino*)malloc(sizeof(tetrimino))))
		return (NULL);
	if (coord)
	{
		i = -1;
		while (++i < 4)
		{
			(tetri->coord)[i][0] = coord[i][0];
			(tetri->coord)[i][1] = coord[i][1];
		}
	}
	tetri->next = NULL;
	tetri->previous = NULL;
	return (tetri);
}

void		add_tetrimino(tetrimino **alst, tetrimino *new)
{
	new->next = *alst;
	*alst = new;
}

void		del_tetrimino(tetrimino **alst)
{
	if ((*alst)->next)
		del_tetrimino(&(*alst)->next);
	if (alst && *alst)
		ft_memdel((void**)(*alst)->coord);
	ft_memdel((void**)alst);
}

void		iter_tetrimino(tetrimino *lst, void (*f)(tetrimino *tetri))
{
	tetrimino	*begin;

	begin = lst;
	while (begin)
	{
		f(begin);
		begin = begin->next;
	}
}

tetrimino	*map_tetrimino(tetrimino *lst, tetrimino *(*f)(tetrimino *tetri))
{
	tetrimino *newelem;

	if (!(newelem = new_tetrimino((int**)f(lst)->coord)))
		return (NULL);
	if (lst->next)
		newelem->next = map_tetrimino(lst->next, f);
	return (newelem);
}