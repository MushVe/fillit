/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:42:06 by cseguier          #+#    #+#             */
/*   Updated: 2018/11/26 14:36:01 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	if (alst != NULL && del != NULL)
	{
		list = (*alst)->next;
		while (list)
		{
			list = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			ft_memdel((void **)alst);
			(*alst) = list;
		}
	}
}
