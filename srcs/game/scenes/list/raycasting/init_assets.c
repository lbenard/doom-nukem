/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:00:19 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 13:56:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "ft/str.h"

static void	init_hud(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.use_key_spritesheet,
		spritesheet("resources/sprites/use-key.bmp", ft_usize(2, 1)));
	module_add(&self->super.module, &self->assets.pick_key_spritesheet,
		spritesheet("resources/sprites/pick-key.bmp", ft_usize(2, 1)));
}

static void	init_game_over(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.game_over_background,
		frame_from_file("resources/textures/blood-background.bmp"));
	module_add(&self->super.module, &self->assets.game_over,
		text("resources/fonts/haxorville.bmp",
			ft_usize(5 * ft_strlen("Account closed."), 9)));
	if (self->super.module.has_error == FALSE)
	{
		text_set_ref(&self->assets.game_over,
			static_string_as_ref(ft_static_string("Account closed.")));
		text_render(&self->assets.game_over,
			ft_text_settings(ft_isize(0, 0), 9));
	}
}

static void	init_monsters(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.alien_spritesheet,
		spritesheet("resources/sprites/weirdalien-spritesheet.bmp",
			ft_usize(17, 8)));
	module_add(&self->super.module, &self->assets.widepunchman_spritesheet,
		spritesheet("resources/sprites/widepunchman-spritesheet.bmp",
			ft_usize(9, 4)));
	module_add(&self->super.module, &self->assets.ghast_spritesheet,
		spritesheet("resources/sprites/ghast-spritesheet.bmp", ft_usize(3, 5)));
	module_add(&self->super.module, &self->assets.fireball_spritesheet,
		spritesheet("resources/sprites/fireball-spritesheet.bmp",
			ft_usize(6, 4)));
	module_add(&self->super.module, &self->assets.nyarlathotep_spritesheet,
		spritesheet("resources/sprites/nyarlathotep-spritesheet.bmp",
			ft_usize(3, 4)));
}

static void	init_weapons(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.pistol_spritesheet,
		spritesheet("resources/sprites/pistol-spritesheet.bmp",
			ft_usize(4, 4)));
	module_add(&self->super.module, &self->assets.shotgun_spritesheet,
		spritesheet("resources/sprites/shotgun-spritesheet.bmp",
			ft_usize(5, 4)));
	module_add(&self->super.module, &self->assets.minigun_spritesheet,
		spritesheet("resources/sprites/minigun-spritesheet.bmp",
			ft_usize(4, 2)));
	module_add(&self->super.module, &self->assets.ammo_sprite,
		frame_from_file("resources/sprites/ammo-sprite.bmp"));
	module_add(&self->super.module, &self->assets.medikit_sprite,
		frame_from_file("resources/sprites/medikit-sprite.bmp"));
}

void		init_raycasting_scene_assets(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.fallback_texture,
		frame_from_file("resources/textures/fallback.bmp"));
	module_add(&self->super.module, &self->assets.skybox,
		frame_from_file("resources/textures/blood-background.bmp"));
	module_add(&self->super.module, &self->assets.crosshair,
		frame_from_file("resources/textures/crosshair.bmp"));
	init_hud(self);
	init_game_over(self);
	init_monsters(self);
	init_weapons(self);
	module_add(&self->super.module, &self->assets.lamp_sprite,
		frame_from_file("resources/sprites/lamp.bmp"));
}
