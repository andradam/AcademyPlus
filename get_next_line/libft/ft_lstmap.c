/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anadam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 11:33:36 by anadam            #+#    #+#             */
/*   Updated: 2016/12/23 17:58:10 by anadam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	new = (t_list*)malloc(sizeof(t_list));
	tmp = (t_list*)malloc(sizeof(t_list));
	tmp = f(lst);
	new = tmp;
	if (new == NULL || lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		if ((tmp->next) == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (new);
}
