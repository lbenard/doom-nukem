/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:35:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:55:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

void	list_move(t_list_head *list, t_list_head *head)
{
	list_del(list->prev, list->next);
	list_add_entry(list, head);
}
