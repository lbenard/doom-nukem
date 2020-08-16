/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 22:21:39 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 22:41:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

void	init_raycasting_scene_inputs(t_raycasting_scene *const self)
{
	self->inputs.shoot = input_get_id(&game_singleton()->input, "Shoot");
	self->inputs.reload = input_get_id(&game_singleton()->input, "Reload");
	self->inputs.use = input_get_id(&game_singleton()->input, "Use");
	self->inputs.pick = input_get_id(&game_singleton()->input, "Pick");
}
