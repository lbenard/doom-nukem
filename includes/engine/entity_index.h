/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_index.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 02:01:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/05 22:32:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_INDEX_H
# define ENTITY_INDEX_H

# include "containers/module.h"
# include "containers/list.h"
# include "containers/string.h"

typedef struct				s_entity_descriptor_node
{
	t_list_head		node;
	t_static_string	name;
	t_static_string	icon_path;
	t_constructor	(*dnon_entity_constructor)();
}							t_entity_descriptor_node;

t_entity_descriptor_node	*new_entity_descriptor_node(
								const t_static_string name,
								const t_static_string icon_path,
								t_constructor (*entity_constructor)());

typedef struct				s_entity_index
{
	t_module	module;
	t_list_head	descriptors;
}							t_entity_index;

t_constructor				entity_index(void);

t_result					init_entity_index(t_entity_index *const self);

t_result					entity_index_register(t_entity_index *const self,
								t_entity_descriptor_node *const descriptor);
t_constructor				(*entity_index_get(t_entity_index *const self,
								const char *name))();

void						destroy_entity_index(t_entity_index *const self);

#endif