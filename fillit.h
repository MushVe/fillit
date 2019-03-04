/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:47:04 by cseguier          #+#    #+#             */
/*   Updated: 2019/03/04 13:47:40 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

int		is_tetrimino(char *str);
void	normalize_tetri(char *str);
int		***read_file(int fd, int cpt);
int		resolve(int ***coord, int current, int len, int y);
void	free_coord(int ***coord);

#endif
