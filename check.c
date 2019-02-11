/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:02:42 by czhang            #+#    #+#             */
/*   Updated: 2019/02/11 19:56:59 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_valid_char(char c, int i)
{
	if ((i % 5) == 4)
		return (c == '\n');
	else
		return ((c == '.') || (c == '#'));
}

int		count_sharp(char *str)
{
	if (*str == '\0')
		return (0);
	else if (*str == '#')
		return (1 + count_sharp(str + 1));
	else
		return (count_sharp(str + 1));
}

int		neighbors(char *str)
{
	int i;
	int not_yet;
	int	count;

	i = -1;
	count = 1;
	while (++i < 20)
		while (str[i] == '#' && count != 4)
		{
			not_yet = 1;
			while (not_yet)
			{
				if (i + 1 <= 19 && str[i + 1] == '#')
				{
					count++;
					i = i + 1;
					break;
				}
				if (i + 5 <= 19 && str[i + 5] == '#')
				{
					count++;
					i = i + 5;
					break ;
				}
				not_yet--;
			}
			if (not_yet == 0)
				return (0);
		}
	return (1);
}

int		is_tetrimino(char *str)
{
	int	i;

	if (ft_strlen(str) != 20)
	{
		ft_putstr("lol");
		return (0);
	}
	i = -1;
	while (++i < 20)
		if (!is_valid_char(str[i], i))
			return (0);
	if (count_sharp(str) != 4)
		return (0);
	if (neighbors(str) == 0)
		return (0);
	return (1);
}
