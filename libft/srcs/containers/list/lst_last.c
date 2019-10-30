/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 01:08:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:02:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

t_list	*lst_last(const t_list *list)
{
	while (list->next)
		list = list->next;
	return ((t_list*)list);
}
