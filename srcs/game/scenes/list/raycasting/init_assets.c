/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 22:00:19 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/30 04:09:28 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

t_result	init_assets(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->floor,
		frame_from_file("resources/textures/andesite.bmp"));
	module_add(&self->super.module, &self->ceiling,
		frame_from_file("resources/textures/coarse_dirt.bmp"));
	module_add(&self->super.module, &self->crosshair,
		frame_from_file("resources/textures/crosshair-downscale.bmp"));
	module_add(&self->super.module, &self->pistol_ss,
		spritesheet("resources/sprites/pistol_spritesheet.bmp",
			ft_usize(4, 4)));
	module_add(&self->super.module, &self->shotgun_ss,
		spritesheet("resources/sprites/shotgun_ss.bmp",
			ft_usize(5, 4)));
	module_add(&self->super.module, &self->minigun_ss,
		spritesheet("resources/sprites/minigun_ss.bmp",
			ft_usize(4, 2)));
	module_add(&self->super.module, &self->pistol,
		sound("resources/sound/ar15-pistol-shot.wav"));
	module_add(&self->super.module, &self->alien_spritesheet,
		spritesheet("resources/sprites/wow.bmp",
			ft_usize(17, 8)));
	module_add(&self->super.module, &self->onepunchman_spritesheet,
		spritesheet("resources/sprites/sprite-sheet-png-walking-2.bmp",
			ft_usize(9, 4)));
	module_add(&self->super.module, &self->ghast_spritesheet,
		spritesheet("resources/sprites/ghast.bmp",
			ft_usize(3, 4)));
	module_add(&self->super.module, &self->hud_ray,
		hud_game("resources/sprites/heart_disintegration.bmp",
			"resources/sprites/sprite-sheet-png-walking-2.bmp"));
	return (self->super.module.has_error == TRUE);
}