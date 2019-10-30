/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_content_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:20:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 20:20:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"
#include "ft/mem.h"
#include "maths/maths.h"

t_list	*lst_content_find(const t_list *lst, const void *to_find,
	size_t to_find_size)
{
	if (to_find)
		while (lst)
		{
			if (ft_memcmp(lst->content, to_find, ft_min(lst->content_size,
					to_find_size)) == 0)
				return ((t_list*)lst);
			lst = lst->next;
		}
	return (NULL);
}
