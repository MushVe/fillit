/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:40:33 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/13 18:47:28 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

static int		potati(int ***wesh, int cpt)
{
	int i = 0;
	int j = 0;

	while (i < cpt)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(wesh[i][j][0]); ft_putstr("; ");
			ft_putnbr(wesh[i][j][1]); ft_putstr("\n");
			j++;
		}
		i++;
	}
	return (0);
}

static int		***extract(char *s, int cpt)
{
	int		***coord;
	int		i;
	int		j;
	int		x;

	j = 0;
	x = -1;
	if (!(coord = (int***)ft_memalloc(sizeof(int**) * cpt)))
		return (0);
	while (++x < cpt)
	{
//		ft_putstr("x: "); ft_putnbr(x); ft_putendl("");
		if (!(coord[x] = (int**)ft_memalloc(sizeof(int*) * 4)))
			return (0);
		i = -1;
		while (++i < 4)
		{
//			ft_putstr("i: "); ft_putnbr(i); ft_putendl("");
			if (!(coord[x][i] = (int*)ft_memalloc(sizeof(int) * 2)))
				return (0);
		}
	}
	x = -1;
	while (++x < cpt)
	{
//		ft_putstr("\t\tx: "); ft_putnbr(x); ft_putendl("");
		i = -1;
		j = 0;
		while (++i < 20)
		{
//			ft_putstr("i: "); ft_putnbr(i); ft_putendl("");
			if (s[i + x * 20] == '#')
			{
//				ft_putstr("\tj: "); ft_putnbr(j); ft_putendl("");
				coord[x][j][0] = i % 5;
//				ft_putendl("000");
				coord[x][j][1] = i / 5;
				j++;
			}
		}
	}
//	ft_putendl("666");
	return (coord);
}

int				read_file(char *file_name)
{
	int		fd;
	char	*s;
	char	buff[BUFF_SIZE + 1];
	ssize_t	rd;
	int		cpt;
	int ***tost;

	ft_memset(buff, 0, BUFF_SIZE + 1);
	fd = open(file_name, O_RDONLY);
	cpt = 0;
	s = "\0";
	while (0 < (rd = read(fd, buff, BUFF_SIZE)))
	{
		if (rd == -1)
			return (0);
		if (buff[19] == '\n' && buff[20] == '\n')
			buff[20] = '\0';
		if (!is_tetrimino(buff))
			return (0);
		cpt++;
		move_coord(buff);
		//		ft_putstr(buff);
		if (!(s = ft_strjoin(buff, s)))
			return (0);
		ft_memset(buff, 0, BUFF_SIZE + 1);
	}
//		ft_putstr(s);
	if (!(tost = extract(s, cpt)))
		return (0);
	potati(tost, cpt);
	return (1);
}
