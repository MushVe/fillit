/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:02:42 by czhang            #+#    #+#             */
/*   Updated: 2019/02/27 12:53:06 by cseguier         ###   ########.fr       */
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

static int	neighbors(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < 20)
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && (str[i + 1] == '#'))
				count++;
			if ((i - 1) >= 0 && (str[i - 1] == '#'))
				count++;
			if ((i + 5) < 20 && (str[i + 5] == '#'))
				count++;
			if ((i - 5) >= 0 && (str[i - 5] == '#'))
				count++;
		}
	return (count == 6 || count == 8);
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
