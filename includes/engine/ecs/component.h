/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:01:37 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:19:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENT_H
# define COMPONENT_H

# include "types.h"
# include "containers/vector.h"
# include "engine/module.h"
# include "engine/entity.h"

typedef size_t		t_component_uid;

/*
** Super-class for any component object.
*/
typedef struct		s_component
{
	t_bool	is_active;
}					t_component;

t_component			ft_component(void);

t_component_uid		get_new_component_uid(void);

/*
** Manager for a specific-type component (fixed size and alignement in list).
** Intended to be stored in a linked list.
*/
typedef struct		s_component_manager
{
	t_list_head			node;
	t_module			module;
	t_component_uid		uid;
	t_vector			list;
	const char			*name;
	t_bool				is_active;
	t_smodule_factory	component_factory;
	size_t				component_size;
}					t_component_manager;

typedef struct		s_component_manager_args
{
	const char			*name;
	t_smodule_factory	component_factory;
	size_t				component_size;
}					t_component_manager_args;

t_smodule_factory	component_manager(const char *name,
						const t_smodule_factory component_factory,
						const size_t component_size);

t_result			init_component_manager(t_component_manager *const self,
						const t_component_manager_args *const args);
t_result			component_manager_add(t_component_manager *const self,
						const t_entity_uid entity_id,
						const void *const component_args);
void				*component_manager_get(t_component_manager *const self,
						const t_entity_uid entity_id);
void				destroy_component_manager(t_component_manager *const self);

#endif