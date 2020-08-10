/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:26:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 21:23:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "game/entities/pistol_entity.h"
#include "engine/error.h"
#include "engine/image.h"
#include "game/game.h"
#include "ft/str.h"

static void	add_modules(t_raycasting_scene *const self,
				const t_raycasting_scene_args *const args)
{
	init_assets(self);
	module_add(&self->super.module, &self->map, map(args->path));
	module_add(&self->super.module, &self->zbuffer,
		array(sizeof(t_ray) * args->window->size.x));
	module_add(&self->super.module, &self->sprite_entities, entity_list());
	module_add(&self->super.module, &self->monster_entities, entity_list());
	module_add(&self->super.module, &self->weapon_entities, entity_list());
	module_add(&self->super.module, &self->weapon.display_text,
		text("haxorville.bmp", ft_usize(args->window->size.x, 9)));
	module_add(&self->super.module, &self->assets.game_over,
		text("haxorville.bmp", ft_usize(5 * ft_strlen("ur ded lol"), 9)));
}

static void	add_entities(t_raycasting_scene *const self)
{
	t_list_head			*pos;
	t_map_entity_node	*node;
	t_entity_descriptor	*descriptor;

	self->entities.player_ref = (t_player_entity*)entity_list_add_entity(
		&self->super.entities, player_entity(&self->map, self->fov));
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
			{
				if (raycasting_scene_add_entity(self, descriptor, node->pos) == ERROR)
					return ;
			}
		}
	}
	self->entities.weapon_ref = (t_weapon_entity*)entity_list_add_entity(
		&self->super.entities,
		pistol_entity((t_scene*)self, ft_vec2f(0.0f, 0.0f)));
}

static void	init_vars(t_raycasting_scene *const self,
				t_raycasting_scene_args *const args)
{
	self->path = args->path;
	self->death_time = 0.0f;
	self->fov = 90.0f * M_PI / 180.0f;
	self->window_ref = args->window;
	self->entities.weapon_ref = NULL;
	self->weapon.ammo = 100;
	self->weapon.last_shot = 0.0;
	self->inputs.shoot = input_get_id(&game_singleton()->input, "Shoot");
	self->inputs.reload = input_get_id(&game_singleton()->input, "Reload");
	self->inputs.use = input_get_id(&game_singleton()->input, "Use");
}

static void	add_death_buttons(t_raycasting_scene *const self,
				t_raycasting_scene_args *const args)
{
	self->entities.retry_button_ref = (t_button_entity*)entity_list_add_entity(
		&self->super.entities,
		dynamic_button_entity("resources/buttons/retry-button-upscale.bmp",
			"resources/buttons/retry-button-hover-upscale.bmp",
			"resources/buttons/retry-button-click-upscale.bmp",
			args->window));
	if (self->entities.retry_button_ref)
		self->entities.retry_button_ref->super.transform.position =
			ft_vec3f(-9999.0f, -9999.0f, 0.0f);
	self->entities.give_up_button_ref = (t_button_entity*)entity_list_add_entity(
		&self->super.entities,
		dynamic_button_entity("resources/buttons/give-up-button-upscale.bmp",
			"resources/buttons/give-up-button-hover-upscale.bmp",
			"resources/buttons/give-up-button-click-upscale.bmp",
			args->window));
	if (self->entities.give_up_button_ref)
		self->entities.give_up_button_ref->super.transform.position =
			ft_vec3f(-9999.0f, -9999.0f, 0.0f);
}

static void	init_use_key_tooltip(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.use_key_spritesheet,
		spritesheet("resources/sprites/use_key.bmp", ft_usize(2, 1)));
	module_add(&self->super.module, &self->assets.use_key_animation,
		animation(0, 2, 0.1f));
	module_add(&self->super.module, &self->assets.use_key_text,
		text("haxorville.bmp", ft_usize(5 * ft_strlen("Press"), 9)));
	if (self->super.module.has_error == FALSE)
	{
		text_set_ref(&self->assets.use_key_text,
			static_string_as_ref(ft_static_string("Press")));
		text_render(&self->assets.use_key_text, ft_text_settings(ft_isize(0, 0), 9));
		frame_fill_blend(&self->assets.use_key_text.target,
			ft_rgba(255, 255, 255, 255), blend_colorize);
	}
}

t_result	init_raycasting_scene(t_raycasting_scene *const self,
				t_raycasting_scene_args *const args)
{
	if (!init_scene(&self->super, "Raycasting",
		raycasting_scene_update, raycasting_scene_render))
	{
		return (throw_result_str("init_raycasting_scene()",
			"failed while initalizing scene"));
	}
	init_vars(self, args);
	add_modules(self, args);
	init_use_key_tooltip(self);
	if (!self->super.module.has_error)
	{
		add_entities(self);
		add_death_buttons(self, args);
	}
	if (self->super.module.has_error || self->super.entities.module.has_error)
	{
		destroy_raycasting_scene(self);
		return (throw_result_str("init_raycasting_scene()",
			"failed to create"));
	}
	text_set_ref(&self->assets.game_over,
		static_string_as_ref(ft_static_string("ur ded lol")));
	text_render(&self->assets.game_over, ft_text_settings(ft_isize(0, 0), 9));
	return (OK);
}
