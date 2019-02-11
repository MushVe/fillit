/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:59:21 by czhang            #+#    #+#             */
/*   Updated: 2018/11/20 23:21:05 by czhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newelem;

	if (!(newelem = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	if (lst->next)
		newelem->next = ft_lstmap(lst->next, f);
	return (newelem);
}
