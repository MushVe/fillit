/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:42:59 by czhang            #+#    #+#             */
/*   Updated: 2019/02/11 19:59:43 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char	str1[21] = "...#\n...#\n...#\n...#\n\0";
	char	str2[21] = "...#\n...#\n...#\n..#.\n\0";

	if (ac != 2)
		ft_putendl("usage: ./fillit tetrimos_file");
	else
	{
		av[1] = "lol";
		ft_putendl("str1 :");
		ft_putendl(str1);
		ft_putstr("neighbors(str1) : ");
		ft_putnbr(neighbors(str1));
		ft_putendl("");
		ft_putstr("is_tetrimino(str1) : ");
		ft_putnbr(is_tetrimino(str1));
		ft_putendl("\n");
		ft_putendl("str2 :");
		ft_putendl(str2);
		ft_putstr("neighbors(str2) : ");
		ft_putnbr(neighbors(str2));
		ft_putendl("");
		ft_putstr("is_tetrimino(str2) : ");
		ft_putnbr(is_tetrimino(str2));
		ft_putendl("\n");
	}
	return (0);
}
