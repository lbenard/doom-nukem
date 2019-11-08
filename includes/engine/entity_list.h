/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:14:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:41:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_LIST_H
# define ENTITY_LIST_H

# include "containers/module.h"
# include "engine/classic_entity.h"
# include "containers/list.h"
# include "containers/vector.h"

/*
** Entity batch used in scenes
*/
typedef struct		s_entity_list
{
	t_module	module;
	t_vector	batch;
	t_list_head	list;
}					t_entity_list;

t_constructor		entity_list(void);

t_result			init_entity_list(t_entity_list *const self);

t_classic_entity	*entity_list_add_entity(t_entity_list *const self,
						const t_constructor constructor);
void				entity_list_update(t_entity_list *const self);

void				destroy_entity_list(t_entity_list *const self);

#endif
