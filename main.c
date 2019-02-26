/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:42:59 by czhang            #+#    #+#             */
/*   Updated: 2019/02/22 18:29:54 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_tab(int ***coord)
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

static int		err(const char *error_str)
{
	ft_putendl(error_str);
	return (0);
}

static int		*resize_is_empty(int len)
{
	int	*tab;
	int	i;

//	ft_memdel((void**)&is_empty);
	if (!(tab = (int*)malloc(sizeof(int) * len * len)))
		return (0);
	i = -1;
	while (++i < len * len)
		tab[i] = 1;
	return (tab);
}

int			main(int ac, char **av)
{
	int	***coord;
	int	len;
	int	fd;
	int	is_transposed;
	int	*is_empty;

	if (ac != 2)
		return (err("usage: ./fillit tetrimos_file"));
	if (0 > (fd = open(av[1], O_RDONLY)))
		return (err("error"));
	if (!(coord = read_file(fd, 0)))
		return (err("error"));
	is_transposed = is_big_x(coord);
	len = 2;
	if (!(is_empty = resize_is_empty(len)))
		return (err("error"));
	while (!resolve(coord, 0, len, 0, is_empty))
		if (!(is_empty = resize_is_empty(++len)))
			return ((err("error")));
	if (is_transposed)
		swap_x_y(coord);
	print(coord, len);
	free_tab(coord);
	ft_memdel((void**)&is_empty);
	return (1);

}
