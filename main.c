/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:42:59 by czhang            #+#    #+#             */
/*   Updated: 2019/02/15 19:43:33 by czhang           ###   ########.fr       */
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
	int ***res;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit tetrimos_file");
		return (0);
	}

	if (!(res = read_file(av[1])))
	{
		ft_putendl("error");
		return (0);
	}
	resolve(res, 0);
	print(res, 5, 4);
	//	resolve(res);

	return (0);
}
