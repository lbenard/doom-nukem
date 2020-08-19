/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:00:19 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 01:27:45 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "ft/str.h"

static void	init_hud(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.use_key_spritesheet,
		spritesheet("resources/sprites/use_key.bmp", ft_usize(2, 1)));
	module_add(&self->super.module, &self->assets.pick_key_spritesheet,
		spritesheet("resources/sprites/pick_key.bmp", ft_usize(2, 1)));
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
	module_add(&self->super.module, &self->assets.widepunchman_spritesheet,
		spritesheet("resources/sprites/widepunchman_spritesheet.bmp",
			ft_usize(9, 4)));
	module_add(&self->super.module, &self->assets.ghast_spritesheet,
		spritesheet("resources/sprites/ghast.bmp", ft_usize(3, 5)));
	module_add(&self->super.module, &self->assets.fireball_spritesheet,
		spritesheet("resources/sprites/fireball_ss.bmp", ft_usize(6, 4)));
	module_add(&self->super.module, &self->assets.nyarlathotep_spritesheet,
		spritesheet("resources/sprites/nyarlathotep.bmp", ft_usize(3, 4)));
}

static void	init_weapons(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.pistol_spritesheet,
		spritesheet("resources/sprites/pistol_spritesheet.bmp",
			ft_usize(4, 4)));
	module_add(&self->super.module, &self->assets.shotgun_spritesheet,
		spritesheet("resources/sprites/shotgun_ss.bmp", ft_usize(5, 4)));
	module_add(&self->super.module, &self->assets.minigun_spritesheet,
		spritesheet("resources/sprites/minigun_ss.bmp", ft_usize(4, 2)));
	module_add(&self->super.module, &self->assets.ammo_sprite,
		frame_from_file("resources/sprites/ammo_sprite.bmp"));
	module_add(&self->super.module, &self->assets.medikit_sprite,
		frame_from_file("resources/sprites/medikit_sprite.bmp"));
}

void		init_raycasting_scene_assets(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->assets.floor,
		frame_from_file("resources/textures/andesite.bmp"));
	module_add(&self->super.module, &self->assets.ceiling,
		frame_from_file("resources/textures/coarse_dirt.bmp"));
	module_add(&self->super.module, &self->assets.crosshair,
		frame_from_file("resources/textures/crosshair-downscale.bmp"));
	init_hud(self);
	init_game_over(self);
	init_monsters(self);
	init_weapons(self);
}
