/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 01:12:05 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 21:00:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_checkbox_entity.h"

t_entity_checkbox_entity	*create_entity_checkbox(t_entity_list *const list,
								const char *const base_name,
								const t_entity_descriptor *const entity,
								const t_window *const window)
{
	t_entity_checkbox_entity	*ret;

	ret = (t_entity_checkbox_entity*)entity_list_add_entity(list,
		entity_checkbox_entity(base_name, entity, window));
	return (ret);
}
