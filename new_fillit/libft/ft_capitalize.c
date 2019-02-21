/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:12:21 by cseguier          #+#    #+#             */
/*   Updated: 2018/12/05 19:30:13 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_capitalize2(char *str)
{
	int mot;
	int i;

	i = 0;
	mot = 1;
	while (str[i] != '\0')
	{
		if (!(ft_isalnum(str[i])))
			mot = 1;
		if (mot == 1 && ft_isalnum(str[i]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
			mot = 0;
		}
		i++;
	}
	return (str);
}

char	*ft_capitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	str = ft_capitalize2(str);
	return (str);
}
