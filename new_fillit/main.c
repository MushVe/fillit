/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:31:11 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/21 15:51:35 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char	*s;
	char	**stock;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit tetrimos_file");
		return (0);
	}
	if (!(s = read_file(open(av[1], O_RDONLY))))
	{
		ft_putendl("error");
		return (0);
	}
	if (!(stock = extract(s)))
		return (0);
//	ft_memdel((void*)s);
//	ft_print_words_tables(stock);
	if (!(s = resolve(stock)))
		return (0);
	return (0);
}
