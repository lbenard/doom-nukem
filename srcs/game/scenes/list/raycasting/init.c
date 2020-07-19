/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:26:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 21:22:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"
#include "engine/image.h"
#include "game/game.h"
#include "ft/str.h"

static void	add_modules(t_raycasting_scene *const self,
				const t_raycasting_scene_args *const args)
{
	module_add(&self->super.module, &self->floor,
		frame_from_file("resources/textures/pack/block/andesite.png"));
	module_add(&self->super.module, &self->ceiling,
		frame_from_file("resources/textures/pack/block/coarse_dirt.png"));
	module_add(&self->super.module, &self->map, map(args->path));
	module_add(&self->super.module, &self->zbuffer,
		array(sizeof(t_ray) * args->window->size.x));
	module_add(&self->super.module, &self->sprite_entities, entity_list());
	module_add(&self->super.module, &self->monster_entities, entity_list());
	module_add(&self->super.module, &self->crosshair,
		frame_from_file("resources/textures/crosshair-downscale.png"));
	module_add(&self->super.module, &self->pistol,
		sound("resources/sound/ar15-pistol-shot.wav"));
	module_add(&self->super.module, &self->weapon.display_text,
		text("haxorville.png", ft_usize(args->window->size.x, 9)));
	module_add(&self->super.module, &self->ss,
		spritesheet("resources/sprites/wow.bmp",
			ft_usize(17, 8)));
}

static void	add_entities(t_raycasting_scene *const self)
{
	t_list_head			*pos;
	t_map_entity_node	*node;
	t_entity_descriptor	*descriptor;

	self->player_ref = (t_player_entity*)entity_list_add_entity(
		&self->super.entities, player_entity(&self->map));
	if (!self->super.module.has_error)
	{
		pos = &self->map.entities;
		while ((pos = pos->next) != &self->map.entities)
		{
			node = (t_map_entity_node*)((t_u8*)pos
				- __builtin_offsetof(t_map_entity_node, node));
			descriptor = entity_descriptor_from_name(
				(t_entity_descriptor*)&game_singleton()->entities_list,
				sizeof(game_singleton()->entities_list)
					/ sizeof(t_entity_descriptor),
				node->name);
			if (descriptor)
				raycasting_scene_add_entity(self, descriptor, node->pos);
		}
	}
}

static void	init_vars(t_raycasting_scene *const self,
				t_raycasting_scene_args *const args)
{
	self->ground_color = ft_rgb(105, 105, 105);
	self->sky_color = ft_rgb(135, 206, 235);
	self->fov = 90.0f * M_PI / 180.0f;
	self->window_ref = args->window;
	// raycasting_scene_weapon_set_pistol(self);
	raycasting_scene_weapon_set_minigun(self);
	self->weapon.just_shooted = FALSE;
	self->weapon.just_reloaded = FALSE;
	self->weapon.first_render = TRUE;
	self->weapon.shoot_input = input_get_id(&game_singleton()->input, "Shoot");
	self->weapon.reload_input = input_get_id(&game_singleton()->input, "Reload");
}

t_result	init_raycasting_scene(t_raycasting_scene *const self,
				t_raycasting_scene_args *const args)
{
	if (!init_scene(&self->super, "Raycasting sandbox",
		(void(*)())raycasting_scene_update, (void(*)())raycasting_scene_render))
	{
		return (throw_result_str("init_raycasting_scene()",
			"failed while initalizing scene"));
	}
	add_modules(self, args);
	if (!self->super.module.has_error)
		add_entities(self);
	if (!self->super.module.has_error
		&& !self->super.entities.module.has_error)
		init_vars(self, args);
	else
	{
		destroy_raycasting_scene(self);
		return (throw_result_str("init_raycasting_scene()",
			"failed to create"));
	}
	return (OK);
}
