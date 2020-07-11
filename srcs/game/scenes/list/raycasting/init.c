/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:26:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/11 04:15:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"
#include "engine/image.h"
#include "engine/game.h"

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
		sound("resources/sound/minigun.wav"));
}

static void	add_entities(t_raycasting_scene *const self)
{
	self->player_ref = (t_player_entity*)entity_list_add_entity(
		&self->super.entities, player_entity(&self->map));
	raycasting_scene_add_monster(self,
		monster_entity(100.0f,
			5,
			ft_vec2f(3.0f, 3.0f),
			"resources/textures/tom_nook.png"));
}

static void	init_vars(t_raycasting_scene *const self,
				t_raycasting_scene_args *const args)
{
	self->ground_color = ft_rgb(105, 105, 105);
	self->sky_color = ft_rgb(135, 206, 235);
	self->fov = 90.0f * M_PI / 180.0f;
	self->window_ref = args->window;
	// raycasting_scene_set_weapon_pistol(self);
	raycasting_scene_set_weapon_minigun(self);
	self->shoot_input = input_get_id(&game_singleton()->input, "Shoot");
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
