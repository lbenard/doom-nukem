/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:30:30 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:02:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/list.h"

t_list	*lst_find(const t_list *lst, const void *to_find,
	int (*cmp)(const void*, const void*))
{
	if (to_find && cmp)
		while (lst)
		{
			if (cmp(to_find, lst->content) == 0)
				return ((t_list*)lst);
			lst = lst->next;
		}
	return (NULL);
}
