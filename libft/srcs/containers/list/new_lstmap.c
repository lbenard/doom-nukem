/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 23:15:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:00:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/list.h"

t_list		*new_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*head;
	t_list	*start;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(start = new_lstcpy(tmp->content, tmp->content_size)))
		return (NULL);
	free(tmp);
	head = start;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(head->next = new_lstcpy(tmp->content, tmp->content_size)))
		{
			free_lst(start);
			return (NULL);
		}
		free(tmp);
		lst = lst->next;
		head = head->next;
	}
	return (start);
}
