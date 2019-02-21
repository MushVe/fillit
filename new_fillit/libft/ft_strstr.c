/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:24:27 by cseguier          #+#    #+#             */
/*   Updated: 2018/11/19 17:22:48 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *need)
{
	int	i;
	int	buff;
	int	j;

	i = 0;
	buff = 0;
	if (need[i] == '\0')
		return ((char*)str);
	while (str[buff] != '\0')
	{
		j = 0;
		if (str[buff] == need[j])
		{
			i = buff;
			while (str[i] == need[j] && str[i] != '\0' && need[j] != '\0')
			{
				i++;
				j++;
			}
			if (need[j] == '\0')
				return ((char*)&str[buff]);
		}
		buff++;
	}
	return (NULL);
}
