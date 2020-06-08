/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:26:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/08 20:02:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"
#include "engine/image.h"

static void	background_frame(t_frame *const frame,
				const t_rgb ground_color,
				const t_rgb sky_color)
{
	t_usize	i;
	float	darkness;

	i = ft_usize(0, 0);
	while (i.y < frame->size.y)
	{
		darkness = (((double)frame->size.y / 2.0f) - (double)i.y);
		darkness /= (((double)frame->size.y / 2.0f)
			- ((i.y < frame->size.y / 2) ? 0 : ((double)frame->size.y)));
		i.x = 0;
		while (i.x < frame->size.x)
		{
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

static void	add_modules(t_raycasting_scene *const self,
				const t_raycasting_scene_args *const args)
{
	module_add(&self->super.module, &self->texture,
		image("resources/textures/wall.png"));
	module_add(&self->super.module, &self->map, map("maps/test_map.dn"));
	module_add(&self->super.module, &self->background,
		frame(args->window->size, ft_rgba(255, 255, 255, 255)));
	module_add(&self->super.module, &self->renderer,
		raycasting(args->window->size, &self->map));
}

static void	add_entities(t_raycasting_scene *const self,
				const t_usize window_size)
{
	self->player_ref = (t_player_entity*)entity_list_add_entity(
		&self->super.entities, player_entity(&self->map));
	// self->minimap_ref = (t_minimap_entity*)entity_list_add_entity(
	// 	&self->super.entities,
	// 	minimap_entity(&self->renderer, ft_usize(200, 200)));
	self->vignette_ref = (t_image_entity*)entity_list_add_entity(
		&self->super.entities,
		image_entity_from_file("resources/textures/vignette-50.png",
			ft_frame_transform_position(ft_isize(window_size.x / 2,
				window_size.y / 2))));
	// self->camera_ref = (t_camera_entity*)entity_list_add_entity(
	// 	&self->super.entities,
	// 	camera_entity()
	// )
}

static void	init_vars(t_raycasting_scene *const self)
{
	self->ground_color = ft_rgb(105, 105, 105);
	self->sky_color = ft_rgb(135, 206, 235);
	background_frame(&self->background, self->ground_color, self->sky_color);
	event_handler_add_sub_handler(&self->super.input_manager,
		&self->player_ref->event_handler);
	self->fov = 66.0f * M_PI / 180.0f;
	// self->renderer.direction = self->player_ref->super.transform.rotation.y;
	// self->renderer.position =
		// vec3f_to_vec2f(self->player_ref->super.transform.position);
}

t_result	init_raycasting_scene(t_raycasting_scene *const self,
				const t_raycasting_scene_args *const args)
{
	if (!init_scene(&self->super, "Raycasting sandbox",
		(void(*)())raycasting_scene_update, (void(*)())raycasting_scene_render))
	{
		return (throw_result_str("init_raycasting_scene()",
			"failed while initalizing scene"));
	}
	add_modules(self, args);
	if (!self->super.module.has_error)
		add_entities(self, args->window->size);
	if (!self->super.module.has_error)
		init_vars(self);
	else
	{
		destroy_raycasting_scene(self);
		return (throw_result_str("init_raycasting_scene()",
			"failed to create"));
	}
	return (OK);
}
