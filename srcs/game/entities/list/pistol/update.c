/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:40:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 00:58:01 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/pistol_entity.h"

static void	pistol_entity_update3(t_pistol_entity *const self)
{
	if (self->super.shooting == TRUE)
	{
		if (self->animation.iter
			>= self->super.hud_ref->grid_size.x * (1 / 0.6) - 1)
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

static void	pistol_entity_update2(t_pistol_entity *const self)
{
	if (self->super.reloading)
	{
		if (self->animation.iter >= self->super.hud_ref->grid_size.x
			* (1 / 0.16f) - 1 && self->animation.speed != 0)
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
}

void		pistol_entity_update(t_pistol_entity *const self)
{
	weapon_entity_update(&self->super);
	animation_update(&self->animation, self->super.hud_ref);
	self->super.just_reloaded = FALSE;
	if (self->super.trigger_reloading)
	{
		self->super.reloading = TRUE;
		self->animation.anim = 1;
		self->animation.speed = 0.16;
		self->animation.iter = 0;
	}
	pistol_entity_update2(self);
	pistol_entity_update3(self);
}
