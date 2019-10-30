/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 04:33:38 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:09:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/list.h"

void	free_lst(t_list *list)
{
	t_list	*head;
	t_list	*next;

	if (list)
	{
		head = list;
		while (head)
		{
			next = head->next;
			free(head->content);
			free(head);
			head = next;
		}
	}
}
