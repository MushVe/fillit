/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 04:53:41 by czhang            #+#    #+#             */
/*   Updated: 2018/11/20 23:56:29 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	c0;
	int		i;
	int		last;

	c0 = (char)c;
	i = -1;
	last = 0;
	while (s[++i])
		if (s[i] == c0)
			last = i;
	if (s[i] == c0)
		return ((char*)(s + i));
	if (s[last] == c0)
		return ((char*)(s + last));
	return (0);
}
