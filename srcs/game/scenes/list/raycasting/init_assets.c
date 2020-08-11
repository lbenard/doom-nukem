/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:00:19 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 22:28:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "ft/str.h"

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
		text_render(&self->assets.use_key_text,
			ft_text_settings(ft_isize(0, 0), 9));
		frame_fill_blend(&self->assets.use_key_text.target,
			ft_rgba(255, 255, 255, 255), blend_colorize);
	}
}

static void	init_game_over(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.game_over_background,
		frame_from_file("resources/textures/blood-background.bmp"));
	module_add(&self->super.module, &self->assets.game_over,
		text("haxorville.bmp", ft_usize(5 * ft_strlen("ur ded lol"), 9)));
	if (self->super.module.has_error == FALSE)
	{
		text_set_ref(&self->assets.game_over,
			static_string_as_ref(ft_static_string("ur ded lol")));
		text_render(&self->assets.game_over,
			ft_text_settings(ft_isize(0, 0), 9));
	}
}

static void	init_monsters(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.alien_spritesheet,
		spritesheet("resources/sprites/wow.bmp", ft_usize(17, 8)));
	module_add(&self->super.module, &self->assets.onepunchman_spritesheet,
		spritesheet("resources/sprites/sprite-sheet-png-walking-2.bmp",
			ft_usize(9, 4)));
	module_add(&self->super.module, &self->assets.ghast_spritesheet,
		spritesheet("resources/sprites/ghast.bmp", ft_usize(3, 5)));
	module_add(&self->super.module, &self->assets.nyarlathotep_spritesheet,
		spritesheet("resources/sprites/nyarlathotep.bmp", ft_usize(3, 4)));
}

static void	init_weapons(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.pistol_spritesheet,
		spritesheet("resources/sprites/pistol_spritesheet.bmp",
			ft_usize(4, 4)));
	module_add(&self->super.module, &self->assets.pistol_sound,
		sound("resources/sound/ar15-pistol-shot.wav"));
	module_add(&self->super.module, &self->assets.shotgun_spritesheet,
		spritesheet("resources/sprites/shotgun_ss.bmp", ft_usize(5, 4)));
	module_add(&self->super.module, &self->assets.minigun_spritesheet,
		spritesheet("resources/sprites/minigun_ss.bmp", ft_usize(4, 2)));
}

void		init_raycasting_scene_assets(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.floor,
		frame_from_file("resources/textures/andesite.bmp"));
	module_add(&self->super.module, &self->assets.ceiling,
		frame_from_file("resources/textures/coarse_dirt.bmp"));
	module_add(&self->super.module, &self->assets.crosshair,
		frame_from_file("resources/textures/crosshair-downscale.bmp"));
	init_use_key_tooltip(self);
	init_game_over(self);
	init_monsters(self);
	init_weapons(self);
}
