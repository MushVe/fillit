/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:40:33 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/15 11:36:40 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		print_couple(int *couple)
{
	ft_putchar('(');
	ft_putnbr(couple[0]);
	ft_putstr("; ");
	ft_putnbr(couple[1]);
	ft_putstr(")\n");
}

static void		free_tab(int cpt)
{
	int	i_cpt;
	int i_block;

	i_cpt = -1;
	while (++i_cpt < cpt)
		i_block = -1;
		while (++i_block < 4)
		{
			ft_memdel((void**));
}

static int		***malloc_tab(int cpt)
{
	int	***coord;
	int	i_cpt;
	int	i_block;

	if (!(coord = (int***)ft_memalloc(sizeof(int**) * cpt)))
		return (0);
	i_cpt = -1;
	while (++i_cpt < cpt)
	{
		if (!(coord[i_cpt] = (int**)ft_memalloc(sizeof(int*) * 4)))
			return (0);
		i_block = -1;
		while (++i_block < 4)
		{
			if (!(coord[i_cpt][i_block] = (int*)ft_memalloc(sizeof(int) * 2)))
				return (0);
		}
	}
	return (coord);
}
static int		***extract(char *s, int cpt)
{
	int	***coord;
	int i_cpt;
	int	i_block;
	int i;

	if (!(coord = malloc_tab(cpt)))
		return (0);
	i_cpt = -1;
	while (++i_cpt < cpt)
	{
		i = -1;
		i_block = 0;
		while (++i < 20)
			if (s[i + i_cpt * 20] == '#')
			{
				coord[i_cpt][i_block][0] = i % 5;
				coord[i_cpt][i_block][1] = i / 5;
				i_block++;
			}
	}
	return (coord);
}

int				read_file(char *file_name)
{
	int		fd;
	char	*s;
	char	buff[BUFF_SIZE + 1];
	ssize_t	rd;
	int		cpt;
	int		***tost;

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
	iter_coord(tost, cpt, print_couple);
	return (1);
}
