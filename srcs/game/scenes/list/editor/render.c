/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:32:07 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/27 18:35:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"

static void	render_preview_buttons(t_editor_scene *const self,
				t_frame *const fb)
{
	t_block_checkbox_entity	**list;
	size_t					size;
	size_t					i;
	t_block_checkbox_entity	*hovered;

	hovered = NULL;
	list = (t_block_checkbox_entity**)&self->hud.blocks_group;
	size = sizeof(self->hud.blocks_group) / sizeof(*list);
	i = 0;
	while (i < size)
	{
		if (!hovered && list[i]->super.super.is_hovered)
			hovered = list[i];
		block_checkbox_entity_render(list[i], fb);
		i++;
	}
	if (hovered)
		block_checkbox_entity_render(hovered, fb);
}

static void	render_entity_buttons(t_editor_scene *const self,
				t_frame *const fb)
{
	t_entity_checkbox_entity	**list;
	size_t						size;
	size_t						i;

	list = (t_entity_checkbox_entity**)&self->hud.entities_group;
	size = sizeof(self->hud.entities_group) / sizeof(*list);
	i = 0;
	while (i < size)
	{
		entity_checkbox_entity_render(list[i], fb);
		i++;
	}
}

void	editor_scene_render(t_editor_scene *const self,
			t_frame *const fb)
{
	t_list_head			*pos;
	t_component_entity	*component;

	frame_fill(fb, ft_rgba(0, 0, 0, 255));
	if (sfKeyboard_isKeyPressed(sfKeyB))
		frame_layer_transform_add(fb,
			&self->editor_background,
			ft_frame_transform(ft_vec2f(1.0f, 0.5f),
				ft_isize(fb->size.x + 100, fb->size.y / 2),
				ft_vec2f(2.0f, 2.0f),
				64));
	frame_fill(&self->editor_view, ft_rgba(34, 75, 120, 255));
	pos = &self->components.list;
	while ((pos = pos->next) != &self->components.list)
	{
		component = (t_component_entity*)((t_entity_node*)pos)->entity;
		component->vtable.render(component, self->camera_ref, &self->editor_view);
	}
	frame_layer_add(fb, &self->editor_view, ft_isize(0, 0));
	checkbox_entity_render(self->hud.tools_group.create_ref, fb);
	checkbox_entity_render(self->hud.tools_group.cursor_ref, fb);
	checkbox_entity_render(self->hud.tools_group.save_ref, fb);
	checkbox_entity_render(self->hud.create_group.show_blocks_ref, fb);
	checkbox_entity_render(self->hud.create_group.show_entities_ref, fb);
	render_preview_buttons(self, fb);
	render_entity_buttons(self, fb);
}
