/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:25:47 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:48:13 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/list.h"

size_t	list_size(const t_list_head *head)
{
	const t_list_head	*pos;
	size_t				count;

	pos = head;
	count = 0;
	while ((pos = pos->next) != head)
		count++;
	return (count);
}
