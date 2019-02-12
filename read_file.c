/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 16:40:33 by cseguier          #+#    #+#             */
/*   Updated: 2019/02/12 18:05:18 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

#define BUFF_SIZE 21



int	read_file(char *file_name)
{
	int	fd;
	char buff[BUFF_SIZE + 1];
	ssize_t lu;

	ft_memset(buff, 0, BUFF_SIZE + 1);
	fd = open(file_name, O_RDONLY);
	while (0 < (lu = read(fd, buff, BUFF_SIZE)))
	{
		if (lu == -1)
			return (0);
		if (buff[19] == '\n' && buff[20] == '\n')
			buff[20] = '\0';
		ft_putendl(buff);
		if (!is_tetrimino(buff))
			return(0);
		ft_memset(buff, 0, BUFF_SIZE + 1);
	}


	return (1);
}
