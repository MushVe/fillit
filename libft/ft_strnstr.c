/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 01:17:32 by czhang            #+#    #+#             */
/*   Updated: 2018/11/21 00:14:37 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;

	if (!*needle)
		return ((char*)haystack);
	while (len && *haystack)
	{
		i = 0;
		while ((len - i) && haystack[i] == needle[i])
		{
			i++;
			if (!len)
				break ;
			if (!needle[i])
				return ((char*)(haystack));
		}
		haystack++;
		len--;
	}
	return (NULL);
}
