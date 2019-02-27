/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:40:33 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/25 16:42:40 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		***malloc_tab(int cpt)
{
	int	***coord;
	int	i_cpt;
	int	i_block;

	if (!(coord = (int***)ft_memalloc(sizeof(int**) * (cpt + 1))))
		return (0);
	coord[cpt] = 0;
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
	{
		free_tab(coord);
		return (0);
	}
	i_cpt = -1;
	while (++i_cpt < cpt)
	{
		i = -1;
		i_block = -1;
		while (++i < 20)
			if ((s[i + i_cpt * 20] == '#') && (++i_block < 4))
			{
				coord[i_cpt][i_block][0] = i % 5;
				coord[i_cpt][i_block][1] = i / 5;
			}
	}
	return (coord);
}

static int		***free_cs(int ***coord, char *s)
{
	free_tab(coord);
	ft_memdel((void**)&s);
	return (0);
}

static char		*dupjoinfree(char *s, const char *buff)
{
	char	*dup;

	dup = ft_strdup(s);
	ft_memdel((void**)&s);
	s = ft_strjoin(dup, buff);
	ft_memdel((void**)&dup);
	return (s);
}

int				***read_file(int fd, int cpt)
{
	char	*s;
	char	buff[21];
	ssize_t	rd;
	int		***coord;

	ft_memset(buff, 0, 21);
	s = ft_strnew(0);
	while (1)
	{
		if (-1 == (rd = read(fd, buff, 20)) || !is_tetrimino(buff))
			return (free_cs(0, s));
		cpt++;
		normalize_tetri(buff);
		if (!(s = dupjoinfree(s, buff)))
			return (free_cs(0, s));
		ft_memset(buff, 0, 21);
		if (0 == (rd = read(fd, buff, 1)))
			break ;
		if (buff[0] != '\n')
			return (0);
	}
	if (!(coord = extract(s, cpt)))
		return (free_cs(coord, s));
	ft_memdel((void**)&s);
	return (coord);
}
