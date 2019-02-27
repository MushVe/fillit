/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:09:44 by czhang            #+#    #+#             */
/*   Updated: 2018/11/19 02:13:29 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && n--)
		i++;
	if (!n)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
