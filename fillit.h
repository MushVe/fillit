/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:11:39 by czhang            #+#    #+#             */
/*   Updated: 2019/02/22 18:24:06 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

int	is_tetrimino(char *str);
void	normalize_tetri(char *str);
int	***read_file(int fd, int cpt);
int	resolve(int ***coord, int current, int len, int y, int *is_empty);
void	free_tab(int ***coord);
int	max(int **current, int xy);
int	*is_big_x(int ***coord);
void	swap_x_y(int ***coord);

#endif
