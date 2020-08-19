/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:40:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 00:49:11 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/shotgun_entity.h"

static void	shotgun_entity_update3(t_shotgun_entity *const self)
{
	if (self->super.shooting == TRUE)
	{
		if (self->animation.iter
			>= self->super.hud_ref->grid_size.x * (1 / 0.5) - 1)
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
			ft_vec2f(3.0f, 3.0f),
			255));
	self->super.trigger_reloading = FALSE;
}

static void	shotgun_entity_update2(t_shotgun_entity *const self)
{
	if (self->super.reloading)
	{
		if (self->animation.iter >= self->super.hud_ref->grid_size.x *
			(1 / 0.2) - 1 && self->animation.speed >= 0.0f)
		{
			self->animation.iter = 0;
			if (self->super.specs.clip == 0)
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
		self->animation.speed = 0.5;
		self->animation.iter = 0;
	}
}

void		shotgun_entity_update(t_shotgun_entity *const self)
{
	weapon_entity_update(&self->super);
	animation_update(&self->animation, self->super.hud_ref);
	self->super.just_reloaded = FALSE;
	if (self->super.trigger_reloading)
	{
		self->super.reloading = TRUE;
		if (self->super.specs.clip == 1)
			self->animation.anim = 3;
		else
			self->animation.anim = 1;
		self->animation.speed = 0.2f;
		self->animation.iter = 0;
	}
	shotgun_entity_update2(self);
	shotgun_entity_update3(self);
}
