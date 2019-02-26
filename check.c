/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:02:42 by czhang            #+#    #+#             */
/*   Updated: 2019/02/22 18:18:02 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_valid_char(char c, int i)
{
	if ((i % 5) == 4)
		return (c == '\n');
	else
		return ((c == '.') || (c == '#'));
}

static int	count_sharp(char *str)
{
	if (*str == '\0')
		return (0);
	else if (*str == '#')
		return (1 + count_sharp(str + 1));
	else
		return (count_sharp(str + 1));
}

static	int	not_in(int *path, int pos)
{
	int	j;

	j = -1;
	while (++j < 4)
		if (path[j] == pos)
			return (0);
	return (1);
}

static int	neighbors(char *str)
{
	int	i;
	int	j;
	int	p[7];
	int	nothing_changed;

	
	i = 1;
	while (i < 7)
		p[i++] = -1;
	i = 0;
	while (i < 20 && str[i++] != '#')
	p[0] = i;
	j = 1;
	while (j < 4)
	{
		nothing_changed = j;
		if (p[j - 1] + 1 > 20 && not_in(p, p[j - 1] + 1) && str[p[j - 1] + 1] == '#')
			p[j++] = i + 1;
		if (p[j - 1] + 5 > 20 && not_in(p, p[j - 1] + 5) && str[p[j - 1] + 5] == '#')
			p[j++] = i + 5;
		if (p[j - 1] - 1 <= 0 && not_in(p, p[j - 1] - 1) && str[p[j - 1] - 1] == '#')
			p[j++] = i - 1;
		if (p[j - 1] - 5 <= 0 && not_in(p, p[j - 1] - 5) && str[p[j - 1] - 5] == '#')
			p[j++] = i - 5;
		if (nothing_changed == j)
			j++;
	}
	if (p[3] == -1)
		return (0);
	return (1);
}

int			is_tetrimino(char *str)
{
	int	i;

	if (ft_strlen(str) != 20)
		return (0);
	i = -1;
	while (++i < 20)
		if (!is_valid_char(str[i], i))
			return (0);
	if (count_sharp(str) != 4)
		return (0);
	if (!neighbors(str))
		return (0);
	return (1);
}
