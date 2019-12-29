/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_node.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:48:17 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/21 02:52:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_NODE_H
# define ENTITY_NODE_H

# include "engine/entity.h"
# include "containers/list.h"

/*
** Entity node used in entity list
*/
typedef struct	s_entity_node
{
	t_list_head		node;
	t_entity*const	entity;
	void			(*free_fn)();
}				t_entity_node;

t_entity_node	*new_entity_node(t_entity *const entity,
					void (*free_fn)());

t_entity		*entity_from_node(t_list_head *const node);

void			free_entity_node(t_entity_node *const node);

#endif
