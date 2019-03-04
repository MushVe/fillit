/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:18:30 by cseguier          #+#    #+#             */
/*   Updated: 2019/03/04 14:21:36 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_coord(int ***coord)
{
	int	i_tetri;
	int	i_block;

	if (coord == 0)
		return ;
	i_tetri = -1;
	while (coord[++i_tetri])
	{
		i_block = -1;
		while (++i_block < 4 && coord[i_tetri][i_block])
			ft_memdel((void**)&coord[i_tetri][i_block]);
		ft_memdel((void**)&coord[i_tetri]);
	}
	ft_memdel((void**)&coord);
}

static char	*init_print(int len)
{
	char	*res;
	int		i;

	if (!(res = ft_strnew((len + 1) * len)))
		return (0);
	i = -1;
	while (++i < (len + 1) * len)
	{
		if (i % (len + 1) == len)
			res[i] = '\n';
		else
			res[i] = '.';
	}
	return (res);
}

static int	print(int ***coord, int len)
{
	char	*str;
	int		i_block;
	int		i_tetri;

	if (!(str = init_print(len)))
		return (0);
	i_tetri = -1;
	while (coord[++i_tetri] != 0)
	{
		i_block = -1;
		while (++i_block < 4)
			str[coord[i_tetri][i_block][0]
				+ coord[i_tetri][i_block][1] * (len + 1)] = 'A' + i_tetri;
	}
	ft_putstr(str);
	ft_memdel((void**)&str);
	return (1);
}

static void	error(int id, int fd)
{
	if (id == 0)
		ft_putendl("usage: ./fillit tetrimos_file");
	if (id == 1 || id == 2)
		ft_putendl("error");
	if (id == 2)
		close(fd);
	exit(0);
}

int			main(int ac, char **av)
{
	int	***coord;
	int	len;
	int	fd;

	if (ac != 2)
		error(0, 0);
	if (0 > (fd = open(av[1], O_RDONLY)))
		error(1, 0);
	if (!(coord = read_file(fd, 0)))
		error(2, fd);
	if (-1 == close(fd))
		error(1, 0);
	len = 2;
	while (!resolve(coord, 0, len, 0))
		len++;
	print(coord, len);
	free_coord(coord);
	return (1);
}
