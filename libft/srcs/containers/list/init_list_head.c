/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:39:20 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:22:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

t_result	init_list_head(t_list_head *list)
{
	if (!list)
		return (ERROR);
	list->next = list;
	list->prev = list;
	return (OK);
}
