/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:40:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 22:31:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/minigun_entity.h"

void	minigun_entity_update(t_minigun_entity *const self)
{
	weapon_entity_update(&self->super);
	animation_update(&self->animation, self->super.hud_ref);
	self->super.just_reloaded = FALSE;
	if (self->super.stopped_shooting)
		self->super.shooting = FALSE;
	if (!(self->super.shooting || self->super.loading))
	{
		self->animation.anim = 0;
		self->animation.iter = 0;
		self->animation.speed = 0.0f;
	}
	else
		self->animation.speed = 0.5f;
	if (self->super.shooting)
		self->animation.anim = 1;
	if (self->super.loading)
		self->animation.anim = 0;
	if (self->super.just_shooted)
	{
		self->super.just_shooted = FALSE;
		self->super.shooting = TRUE;
		self->super.loading = FALSE;
		self->animation.iter = 0;
	}
	frame_fill(&self->super.hud, ft_rgba(0, 0, 0, 0));
	frame_layer_transform_add(&self->super.hud,
		animation_current(&self->animation, self->super.hud_ref),
		ft_frame_transform(ft_vec2f(1.0f, 1.0f),
			ft_isize(self->super.hud.size.x - self->super.hud.size.x / 6,
				self->super.hud.size.y),
			ft_vec2f(3, 3),
			255));
	self->super.trigger_reloading = FALSE;
	self->super.stopped_shooting = FALSE;
}
