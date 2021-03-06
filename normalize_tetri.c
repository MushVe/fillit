/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:48:20 by cseguier          #+#    #+#             */
/*   Updated: 2019/03/04 14:25:16 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_empty_line(char *str, int i)
{
	int	j;

	j = 0;
	while (j < 4 && str[i + j] == '.')
		j++;
	if (j == 4)
		return (1);
	return (0);
}

static int	is_empty_column(char *str, int i)
{
	int	j;

	j = 0;
	while (j < 4 && str[i + j * 5] == '.')
		j++;
	if (j == 4)
		return (1);
	return (0);
}

static void	move_up(char *str)
{
	int	i;
	int	n_lines;
	int	j;

	i = 0;
	n_lines = 0;
	while (is_empty_line(str, i))
	{
		n_lines++;
		i += 5;
	}
	if (n_lines == 0)
		return ;
	i = n_lines * 5;
	ft_memmove((void*)str, (const void*)str + i, 20 - i);
	j = 20 - i;
	while (++j < 20)
		if (j % 5 == 4)
			str[j] = '\n';
		else
			str[j] = '.';
}

static void	move_left(char *str)
{
	int	n_col;
	int	j;
	int	line;

	n_col = 0;
	while (is_empty_column(str, n_col))
		n_col++;
	if (n_col == 0)
		return ;
	line = -1;
	while (++line < 4)
	{
		ft_memmove((void*)str + line * 5,
				(const void*)str + line * 5 + n_col, 4 - n_col);
		j = n_col;
		while (j > 0)
			str[line * 5 + 4 - j--] = '.';
	}
}

void		normalize_tetri(char *str)
{
	move_up(str);
	move_left(str);
}
