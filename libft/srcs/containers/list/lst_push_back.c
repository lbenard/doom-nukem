/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 09:45:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:04:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/list.h"

t_list	*lst_push_back(t_list **list, t_list *new)
{
	t_list	*head;

	if (!list)
		return (NULL);
	if (!*list)
	{
		*list = new;
		return (new);
	}
	head = *list;
	while (head->next)
		head = head->next;
	head->next = new;
	return (head->next);
}
