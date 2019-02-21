/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:31:38 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/21 15:24:10 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 21

char	*read_file(int fd);
int		is_tetrimino(char *str);
void	translate(int ***coord, int crnt_tetri, int plus_x, int plus_y);
void	move_coord(char *str);
void	ft_print_words_tables(char **tab);
char	**extract(char *src);
char	*resolve(char **stock);

#endif
