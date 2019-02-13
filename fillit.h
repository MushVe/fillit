/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:11:39 by czhang            #+#    #+#             */
/*   Updated: 2019/02/13 13:45:44 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# define BUFF_SIZE 21

typedef struct	s_tetrimino
{
	int					coord[4][2];
	struct s_tetrimino	*next;
	struct s_tetrimino	*previous;
}				tetrimino;

int			is_valid_char(char c, int i);

int			count_sharp(char *str);

int			neighbors(char *str);

int			is_tetrimino(char *str);

tetrimino	*new_tetrimino(int **cord);

void		add_tetrimino(tetrimino **alst, tetrimino *new);

void		del_tetrimino(tetrimino **alst);

void		iter_tetrimino(tetrimino *lst, void (*f)(tetrimino *tetri));

tetrimino	*map_tetrimino(tetrimino *lst, tetrimino *(*f)(tetrimino *tetri));

void		move_coord(char *str);

int			read_file(char *file_name);

#endif
