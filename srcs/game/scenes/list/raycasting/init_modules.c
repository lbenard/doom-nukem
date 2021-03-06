/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_modules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 22:20:40 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/09 11:18:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

void	init_raycasting_scene_modules(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->map, map(self->path));
	module_add(&self->super.module, &self->zbuffer,
		array(sizeof(t_ray) * self->window_ref->size.x));
	module_add(&self->super.module, &self->hud_ray,
		hud_game("resources/sprites/heart.bmp"));
	module_add(&self->super.module, &self->last_frame,
		frame(self->window_ref->size, ft_rgba(0, 0, 0, 0)));
}
