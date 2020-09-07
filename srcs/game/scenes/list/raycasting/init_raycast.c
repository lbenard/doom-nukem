/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 11:42:27 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 11:44:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/maths.h"
#include "game/scenes/raycasting_scene.h"

static void	init_steps(t_raycast *const self,
				const t_vec2f pos,
				const t_vec2f dir)
{
	if (dir.x < 0.0f)
	{
		self->step.x = -1;
		self->origin_dist.x = (pos.x - self->ray_pos.x) * self->delta_dist.x;
	}
	else
	{
		self->step.x = 1;
		self->origin_dist.x = (self->ray_pos.x + 1.0f - pos.x)
			* self->delta_dist.x;
	}
	if (dir.y < 0.0f)
	{
		self->step.y = -1;
		self->origin_dist.y = (pos.y - self->ray_pos.y) * self->delta_dist.y;
	}
	else
	{
		self->step.y = 1;
		self->origin_dist.y = (self->ray_pos.y + 1.0f - pos.y)
			* self->delta_dist.y;
	}
}

void		init_raycast(t_raycast *const self,
				const t_vec2f pos,
				const t_vec2f dir)
{
	self->delta_dist = ft_vec2f(ft_fabs(1.0f / dir.x), ft_fabs(1.0f / dir.y));
	self->ray_pos = ft_vec2i((int)pos.x, (int)pos.y);
	self->start_pos = pos;
	self->dir = dir;
	init_steps(self, pos, dir);
}
