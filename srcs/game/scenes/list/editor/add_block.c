/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:37:42 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/09 02:49:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "game/entities/editor/block_component_entity.h"

t_result	editor_scene_add_block(t_editor_scene *const self,
				const t_editor_block_descriptor *const block,
				const t_vec2f pos)
{
	t_component_entity	*new_block;

	if (!(new_block = (t_component_entity*)entity_list_add_entity(
		&self->super.entities,
		block_component_entity(block, &self->blocks))))
		return (ERROR);
	if (!entity_list_add_entity_ref(&self->components, (t_entity*)new_block))
		return (ERROR);
	if (!entity_list_add_entity_ref(&self->blocks, (t_entity*)new_block))
		return (ERROR);
	new_block->super.transform.position = ft_vec3f(pos.x, pos.y, 0.0f);
	return (OK);
}
