/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 23:06:21 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 23:06:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

void	list_swap_next(t_list_head *pos)
{
	t_list_head		*next;
	t_list_head		*left;
	t_list_head		*right;

	next = pos->next;
	left = pos->prev;
	right = next->next;
	left->next = next;
	right->prev = pos;
	pos->prev = next;
	pos->next = right;
	next->prev = left;
	next->next = pos;
}
