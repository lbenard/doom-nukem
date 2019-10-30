/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 15:32:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:54:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

void	list_del_entry(t_list_head *entry)
{
	list_del(entry->prev, entry->next);
	entry->prev = NULL;
	entry->next = NULL;
}
