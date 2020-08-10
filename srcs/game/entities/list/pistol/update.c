/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:40:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 17:45:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/pistol_entity.h"

void	pistol_entity_update(t_pistol_entity *const self)
{
	sprite_entity_update(&self->super.super);
	animation_update(&self->animation, self->super.hud_ref);
	self->super.just_reloaded = FALSE;
	if (self->super.trigger_reloading)
	{
		self->super.reloading = TRUE;
		self->animation.anim = 1;
		self->animation.speed = 0.08;
		self->animation.iter = 0;
	}
	if (self->super.reloading)
	{
		if (self->animation.iter == self->super.hud_ref->grid_size.x
			* (1 / 0.08f) - 1 && self->animation.speed != 0)
		{
			self->animation.iter = 0;
			self->animation.anim++;
			if (self->animation.anim >= 3)
			{
				self->animation.anim = 0;
				self->animation.speed = 0;
				self->super.just_reloaded = TRUE;
				self->super.reloading = FALSE;
			}
		}
	}
	else if (self->super.just_shooted)
	{
		self->super.just_shooted = FALSE;
		self->super.shooting = TRUE;
		self->animation.speed = 0.4;
		self->animation.iter = 0;
	}
	if (self->super.shooting == TRUE)
	{
		if (self->animation.iter
			== self->super.hud_ref->grid_size.x * (1 / 0.4) - 1)
		{
			self->animation.speed = 0;
			self->animation.anim = 0;
			self->super.shooting = FALSE;
		}
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
}
