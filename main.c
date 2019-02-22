/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:42:59 by czhang            #+#    #+#             */
/*   Updated: 2019/02/22 15:31:44 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_test(char *str)
{
//	ft_putendl("str :");
	ft_putstr(str);
//	ft_putstr("cpt > ");
//	ft_putnbr(count_sharp(str));
//	ft_putendl("");
//	ft_putstr("  |  ");
//	ft_putnbr(neighbors(str));
//	ft_putendl("");
//	ft_putstr("  |  ");
	ft_putnbr(is_tetrimino(str));
	ft_putendl("");
}

int		main(int ac, char **av)
{
	int ***coord;
	int	len;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit tetrimos_file");
		return (0);
	}

	if (!(coord = read_file(av[1])))
	{
		ft_putendl("error");
		return (0);
	}

//	len = get_nb_tetri(coord) * 2;
	len = 2;
	while (!resolve(coord, 0, len))
		len++;
	print(coord, len, -1);
	return (0);
}
