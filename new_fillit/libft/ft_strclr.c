/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:10:20 by cseguier          #+#    #+#             */
/*   Updated: 2018/12/05 13:45:33 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (s[++i] != '\0')
		s[i] = '\0';
}
