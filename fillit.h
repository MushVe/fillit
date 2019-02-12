/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:11:39 by czhang            #+#    #+#             */
/*   Updated: 2019/02/12 17:41:24 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct	tetrimino
{
	int[4][2]			coord;
	struct tetrimino	*next;
	struct tetrimino	*previous;
}				tetrimino_list;

int			is_valid_char(char c, int i);

int			count_sharp(char *str);

int			neighbors(char *str);

int			is_tetrimino(char *str);

tetrimino	*new_tetrimino(int **cord);

void		add_tetrimino(tetrimino **alst, tetrimino *new);

void		del_tetrimino(tetrimino **alst);

void		iter_tetrimino(tetrimino *lst, void (*f)(tetrimino *tetri));

tetrimino	map_tetrimino(tetrimino *lst, tetrimino *(*f)(tetrimino *tetri));

#endif
