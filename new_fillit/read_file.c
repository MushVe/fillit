/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:30:34 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/21 15:03:29 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	tetricpt(char *src)
{
	int cpt;

	cpt = ft_strlen(src);
	return (cpt / 4);
}

char		**extract(char *src)
{
	char	**stock;
	int		nb;
	int		tetri_size;
	int		i;

	nb = tetricpt(src);
	i = 0;
	if (!(stock = (char**)ft_memalloc(sizeof(char*) * (nb + 1))))
		return (0);
	nb = 0;
	while (src[i])
	{
		tetri_size = -1;
		if (!(stock[nb] = (char*)ft_memalloc(sizeof(char) * 21)))
			return (0);
		while (++tetri_size != 20)
		{
			stock[nb][tetri_size] = src[i];
			i++;
		}
		nb++;
	}
	return (stock);
}

void		ft_print_words_tables(char **tab)
{
	int	i;
	int	j;

	j = 0;
	if (!tab)
		return ;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			ft_putchar(tab[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

char		*read_file(int fd)
{
	char	*s;
	char	buff[BUFF_SIZE + 1];
	ssize_t	rd;
	int		cpt;

	ft_memset(buff, 0, BUFF_SIZE + 1);
	cpt = 0;
	s = "\0";
	while (0 < (rd = read(fd, buff, BUFF_SIZE)))
	{
		if ((rd == -1) || (buff[20] = '\0' && rd != 0))
			return (0);
		if (buff[19] == '\n' && buff[20] == '\n')
			buff[20] = '\0';
		if (!is_tetrimino(buff))
			return (0);
		cpt++;
		move_coord(buff);
		if (!(s = ft_strjoin(buff, s)))
			return (0);
		ft_memset(buff, 0, BUFF_SIZE + 1);
	}
	return (s);
}
