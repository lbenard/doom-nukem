/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:32:07 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 09:54:54 by lbenard          ###   ########.fr       */
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

static void	render_floor_ceiling(t_editor_scene *const self, t_frame *const fb)
{
	frame_layer_transform_add(fb, &self->set_floor_key, ft_frame_transform(
		ft_vec2f(0.5f, 0.5f), ft_isize(self->editor_view.size.x + 20, fb->size.y
		- 20), ft_vec2f(2.0f, 2.0f), 255));
	frame_layer_transform_add(fb, &self->set_ceiling_key, ft_frame_transform(
		ft_vec2f(0.5f, 0.5f), ft_isize(self->editor_view.size.x + 20, fb->size.y
		- 60), ft_vec2f(2.0f, 2.0f), 255));
	frame_layer_transform_add(fb, &self->set_floor.target, ft_frame_transform(
		ft_vec2f(0.0f, 0.5f), ft_isize(self->editor_view.size.x + 40, fb->size.y
		- 20), ft_vec2f(2.0f, 2.0f), 255));
	frame_layer_transform_add(fb, &self->set_ceiling.target, ft_frame_transform(
		ft_vec2f(0.0f, 0.5f), ft_isize(self->editor_view.size.x + 40, fb->size.y
		- 60), ft_vec2f(2.0f, 2.0f), 255));
	if (self->floor)
		frame_layer_transform_add(fb, &self->floor->texture, ft_frame_transform(
			ft_vec2f(0.5f, 0.5f), ft_isize(self->editor_view.size.x + 180,
			fb->size.y - 20), ft_vec2f(32.0f / self->floor->texture.size.x,
			32.0f / self->floor->texture.size.y), 255));
	if (self->ceiling)
		frame_layer_transform_add(fb, &self->ceiling->texture,
			ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			ft_isize(self->editor_view.size.x + 180, fb->size.y - 60), ft_vec2f(
			32.0f / self->ceiling->texture.size.x, 32.0f
			/ self->ceiling->texture.size.y), 255));
}

static void	render_buttons(t_editor_scene *const self, t_frame *const fb)
{
	checkbox_entity_render(self->hud.tools_group.create_ref, fb);
	checkbox_entity_render(self->hud.tools_group.cursor_ref, fb);
	checkbox_entity_render(self->hud.tools_group.save_ref, fb);
	checkbox_entity_render(self->hud.create_group.show_blocks_ref, fb);
	checkbox_entity_render(self->hud.create_group.show_entities_ref, fb);
	render_preview_buttons(self, fb);
	render_entity_buttons(self, fb);
}

void		editor_scene_render(t_editor_scene *const self,
				t_frame *const fb)
{
	t_list_head			*pos;
	t_component_entity	*component;

	frame_fill(fb, ft_rgba(0, 0, 0, 255));
	if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_B])
		frame_layer_transform_add(fb, &self->editor_background,
			ft_frame_transform(ft_vec2f(1.0f, 0.5f),
				ft_isize(fb->size.x + 100, fb->size.y / 2),
				ft_vec2f(2.0f, 2.0f), 64));
	frame_fill(&self->editor_view, ft_rgba(34, 75, 120, 255));
	pos = &self->components.list;
	while ((pos = pos->next) != &self->components.list)
	{
		component = (t_component_entity*)((t_entity_node*)pos)->entity;
		component->vtable.render(component, self->camera_ref,
			&self->editor_view);
	}
	frame_layer_add(fb, &self->editor_view, ft_isize(0, 0));
	render_buttons(self, fb);
	if (self->hud.create_group.show_blocks_ref->is_active
		&& self->hud.create_group.show_blocks_ref->is_checked)
		render_floor_ceiling(self, fb);
}
