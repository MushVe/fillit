/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:42:59 by czhang            #+#    #+#             */
/*   Updated: 2019/02/11 20:21:58 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_test(char *str)
{
	ft_putendl("str :");
	ft_putstr(str);
	ft_putstr("count_sharp(str) : ");
	ft_putnbr(count_sharp(str));
	ft_putendl("");
	ft_putstr("neighbors(str) : ");
	ft_putnbr(neighbors(str));
	ft_putendl("");
	ft_putstr("is_tetrimino(str) : ");
	ft_putnbr(is_tetrimino(str));
	ft_putendl("\n\n");
}

int		main(int ac, char **av)
{
	char	str1[21] = "...#\n...#\n...#\n...#\n\0";
	char	str2[21] = "...#\n...#\n...#\n..#.\n\0";
	char	str3[21] = "..##\n...#\n...#\n....\n\0";
	char    str4[21] = "..##\n....\n...#\n....\n\0";
	char    str5[21] = ".###\n...#\n...#\n....\n\0";
	char    str6[21] = "####\n...#\n...#\n....\n\0";

	if (ac != 2)
		ft_putendl("usage: ./fillit tetrimos_file");
	else
	{
		av[1] = "lol";
		print_test(str1);
		print_test(str2);
		print_test(str3);
		print_test(str4);
		print_test(str5);
		print_test(str6);
	}
	return (0);
}
