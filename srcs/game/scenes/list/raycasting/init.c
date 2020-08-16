/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:26:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 20:59:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "engine/error.h"

t_result	init_raycasting_scene(t_raycasting_scene *const self,
				t_raycasting_scene_args *const args)
{
	if (!init_scene(&self->super, "Raycasting",
		raycasting_scene_update, raycasting_scene_render))
	{
		return (throw_result_str("init_raycasting_scene()",
			"failed while initalizing scene"));
	}
	init_raycasting_scene_vars(self, args);
	init_raycasting_scene_modules(self);
	init_raycasting_scene_tooltips(self);
	init_raycasting_scene_entity_lists(self);
	init_raycasting_scene_assets(self);
	init_raycasting_scene_inputs(self);
	raycasting_scene_add_entities(self);
	init_raycasting_scene_weapon(self);
	raycasting_scene_add_death_buttons(self);
	if (self->super.module.has_error || self->super.entities.module.has_error)
	{
		destroy_raycasting_scene(self);
		return (throw_result_str("init_raycasting_scene()",
			"failed to create"));
	}
	return (OK);
}
