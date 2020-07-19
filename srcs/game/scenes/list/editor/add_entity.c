/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_entity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:37:42 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 21:30:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "game/entities/editor/entity_component_entity.h"

t_result	editor_scene_add_entity(t_editor_scene *const self,
				const t_entity_descriptor *const entity,
				const t_vec2f pos)
{
	t_component_entity	*new_entity;

	if (!(new_entity = (t_component_entity*)entity_list_add_entity(
		&self->super.entities,
		entity_component_entity(entity, &self->entities))))
		return (ERROR);
	if (!entity_list_add_entity_ref(&self->components, (t_entity*)new_entity))
		return (ERROR);
	if (!entity_list_add_entity_ref(&self->entities, (t_entity*)new_entity))
		return (ERROR);
	new_entity->super.transform.position = ft_vec3f(pos.x, pos.y, 0.0f);
	return (OK);
}
