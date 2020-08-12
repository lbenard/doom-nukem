/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 22:22:16 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/11 05:09:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "game/entities/pistol_entity.h"

void	init_raycasting_scene_weapon(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->weapon.display_text,
		text("haxorville.bmp", ft_usize(self->window_ref->size.x, 9)));
	if (self->super.module.has_error == FALSE)
	{
		self->entities.weapon_ref = (t_weapon_entity*)entity_list_add_entity(
			&self->super.entities,
			pistol_entity((t_scene*)self, ft_vec2f(0.0f, 0.0f)));
	}
}
