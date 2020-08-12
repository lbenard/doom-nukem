/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_death_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 22:23:12 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 22:28:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

void	raycasting_scene_add_death_buttons(t_raycasting_scene *const self)
{
	self->entities.retry_button_ref =
		(t_button_entity*)entity_list_add_entity(&self->super.entities,
		dynamic_button_entity("resources/buttons/retry-button-upscale.bmp",
			"resources/buttons/retry-button-hover-upscale.bmp",
			"resources/buttons/retry-button-click-upscale.bmp",
			self->window_ref));
	if (self->entities.retry_button_ref)
		self->entities.retry_button_ref->super.transform.position =
			ft_vec3f(-9999.0f, -9999.0f, 0.0f);
	self->entities.give_up_button_ref =
		(t_button_entity*)entity_list_add_entity(&self->super.entities,
		dynamic_button_entity("resources/buttons/give-up-button-upscale.bmp",
			"resources/buttons/give-up-button-hover-upscale.bmp",
			"resources/buttons/give-up-button-click-upscale.bmp",
			self->window_ref));
	if (self->entities.give_up_button_ref)
		self->entities.give_up_button_ref->super.transform.position =
			ft_vec3f(-9999.0f, -9999.0f, 0.0f);
}
