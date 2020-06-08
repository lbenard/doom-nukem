/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:15:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/21 06:50:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/entity_node.h"

void	free_entity_node(t_entity_node *const node)
{
	if (!node->is_ref && node->free_fn)
		node->free_fn(node->entity);
	free(node);
}
