/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:11:36 by cseguier          #+#    #+#             */
/*   Updated: 2018/11/28 18:08:51 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int	max;

	max = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			max = 1;
			nb++;
		}
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	if (max == 1)
		ft_putchar_fd((nb % 10) + '1', fd);
	else
		ft_putchar_fd((nb % 10) + '0', fd);
}
