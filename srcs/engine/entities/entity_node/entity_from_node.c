/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_from_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:17:04 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/13 17:27:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity.h"
#include "containers/list.h"
#include "engine/entity_node.h"

t_entity	*entity_from_node(t_list_head *const node)
{
	return (((t_entity_node*)node)->entity);
}
