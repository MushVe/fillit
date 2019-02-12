/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:42:59 by czhang            #+#    #+#             */
/*   Updated: 2019/02/12 14:00:19 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_test(char *str)
{
//	ft_putendl("str :");
	ft_putstr(str);
//	ft_putstr("cpt > ");
	ft_putnbr(count_sharp(str));
//	ft_putendl("");
	ft_putstr("  |  ");
	ft_putnbr(neighbors(str));
//	ft_putendl("");
	ft_putstr("  |  ");
	ft_putnbr(is_tetrimino(str));
	ft_putendl("\n");
}

int		main(int ac, char **av)
{
	char	str1[21] = "...#\n...#\n...#\n...#\n\0";
	char	str2[21] = "..##\n...#\n...#\n....\n\0";
	char	str3[21] = ".#..\n.###\n....\n....\n\0";
	char	str4[21] = "....\n..##\n.##.\n....\n\0";
	char	str5[21] = "..#.\n.##.\n..#.\n....\n\0";
	char	str6[21] = "....\n.#..\n.##.\n..#.\n\0";
	char	str7[21] = "..##\n....\n...#\n....\n\0";
	char	str8[21] = "....\n.###\n.#..\n....\n\0";
	char	str9[21] = "####\n...#\n...#\n....\n\0";
	char	strA[21] = "....\n....\n..##\n..##\n\0";
	char	strB[21] = "...#\n...#\n...#\n..#.\n\0";

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
		print_test(str7);
		print_test(str8);
		print_test(str9);
		print_test(strA);
		print_test(strB);
	}
	return (0);
}
