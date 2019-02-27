/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 01:17:32 by czhang            #+#    #+#             */
/*   Updated: 2018/11/21 00:13:10 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i])
		{
			i++;
			if (!needle[i])
				return ((char*)(haystack));
		}
		haystack++;
	}
	return (NULL);
}
