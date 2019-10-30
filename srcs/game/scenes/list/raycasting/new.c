/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:26:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/27 01:02:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"
#include "engine/image.h"

static void			background_frame(t_frame *const frame,
						const t_rgb ground_color,
						const t_rgb sky_color)
{
	t_usize	i;
	float	darkness;

	i = ft_usize(0, 0);
	while (i.y < frame->size.y)
	{
		i.x = 0;
		while (i.x < frame->size.x)
		{
			darkness = (((double)frame->size.y / 2.0f) - (double)i.y);
			darkness /= (((double)frame->size.y / 2.0f)
				- ((i.y < frame->size.y / 2) ? 0 : ((double)frame->size.y)));
			if (i.y < frame->size.y / 2)
				((t_u32*)frame->frame.array)[i.y * frame->size.x + i.x] =
					ft_rgba(sky_color.r, sky_color.g, sky_color.b,
						255).integer;
			else
				((t_u32*)frame->frame.array)[i.y * frame->size.x + i.x] =
					ft_rgba(ground_color.r * darkness, ground_color.g
					* darkness, ground_color.b * darkness, 255).integer;
			i.x++;
		}
		i.y++;
	}
}

static void			add_modules(t_raycasting_scene *const self,
						const t_raycasting_scene_args *const args)
{
	module_add_hmodule(&self->super.module,
		image_from_file("resources/textures/plaster.jpg"),
		(void**)&self->texture);
	module_add_smodule(&self->super.module, map("maps/test_map.dn"),
		&self->map);
	module_add_smodule(&self->super.module,
		frame(args->window->size, ft_rgba(255, 255, 255, 255)),
		&self->background);
	module_add_smodule(&self->super.module,
		raycasting(args->window->size, &self->map), &self->renderer);
}

static void			add_entities(t_raycasting_scene *const self)
{
	self->player_ref = (t_player_entity*)entity_list_add_entity(
		&self->super.entities, player_entity(&self->map));
	// self->minimap_ref = (t_minimap_entity*)entity_list_add_entity(
	// 	&self->super.entities,
	// 	minimap_entity(&self->renderer, ft_usize(200, 200)));
	self->vignette_ref = (t_image_entity*)entity_list_add_entity(
		&self->super.entities,
		image_entity_from_file("resources/textures/vignette-50.png"));
}

static void			init_vars(t_raycasting_scene *const self)
{
	self->ground_color = ft_rgb(105, 105, 105);
	self->sky_color = ft_rgb(135, 206, 235);
	background_frame(&self->background, self->ground_color, self->sky_color);
	event_handler_add_sub_handler(&self->super.input_manager,
		&self->player_ref->event_handler);
	// self->renderer.direction = self->player_ref->super.transform.rotation.y;
	// self->renderer.position =
		// vec3f_to_vec2f(self->player_ref->super.transform.position);
}

t_raycasting_scene	*new_raycasting_scene(
						const t_raycasting_scene_args *const args)
{
	t_raycasting_scene	*ret;

	if (!(ret = (t_raycasting_scene*)malloc(sizeof(t_raycasting_scene))))
	{
		return (throw_error_str("new_raycasting_scene()",
			"failed while mallocing raycasting scene"));
	}
	if (!init_scene(&ret->super, "Raycasting sandbox",
		(void(*)())raycasting_scene_update, (void(*)())raycasting_scene_render))
	{
		free(ret);
		return (throw_error_str("new_raycasting_scene()",
			"failed while initalizing scene"));
	}
	add_modules(ret, args);
	if (!ret->super.module.has_error)
		add_entities(ret);
	if (!ret->super.module.has_error)
		init_vars(ret);
	else
	{
		free_raycasting_scene(ret);
		return (throw_error_str("new_raycasting_scene()", "failed to create"));
	}
	return (ret);
}
