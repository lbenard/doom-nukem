/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_move_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:12:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:55:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

void	list_move_tail(t_list_head *list, t_list_head *head)
{
	list_del(list->prev, list->next);
	list_add_tail(list, head);
}
