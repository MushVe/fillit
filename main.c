/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:42:59 by czhang            #+#    #+#             */
/*   Updated: 2019/02/22 16:17:34 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int	***coord;
	int	len;
	int	fd;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit tetrimos_file");
		return (0);
	}
	if (0 > (fd = open(av[1], O_RDONLY)))
	{
		ft_putendl("error");
		return (0);
	}
	if (!(coord = read_file(fd, 0)))
	{
		ft_putendl("error");
		return (0);
	}
	len = 2;
	while (!resolve(coord, 0, len, 0))
		len++;
	print(coord, len, -1);
	return (0);
}
