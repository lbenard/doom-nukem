/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_foreach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:47:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:50:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

void	list_foreach(t_list_head *list, size_t offset, void (*fn)())
{
	t_list_head	*pos;
	t_list_head	*next;

	pos = list;
	next = pos->next;
	while ((pos = next) != list)
	{
		next = next->next;
		fn((void*)((t_u8*)pos - offset));
	}
}
