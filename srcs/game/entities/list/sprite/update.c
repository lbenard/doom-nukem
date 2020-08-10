/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 23:43:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/07 14:02:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/sprite_entity.h"
#include "maths/maths.h"

void	sprite_entity_update(t_sprite_entity *const self)
{
	t_vec2f	sprite_pos;
	double	inv_det;
	t_vec2f	transform;
	ssize_t	sprite_screen_x;
	t_usize	sprite_size;

	sprite_pos.x = self->super.transform.position.x
		- self->player_ref->super.transform.position.x;
	sprite_pos.y = self->super.transform.position.y
		- self->player_ref->super.transform.position.y;
	inv_det = 1.0 / (self->player_ref->plane.x * self->player_ref->dir.y
		- self->player_ref->dir.x * self->player_ref->plane.y);
	transform.x = inv_det * (self->player_ref->dir.y * sprite_pos.x
		- self->player_ref->dir.x * sprite_pos.y);
	transform.y = inv_det * (-self->player_ref->plane.y * sprite_pos.x
		+ self->player_ref->plane.x * sprite_pos.y);
	sprite_screen_x = (ssize_t)((self->frame_ref->size.x / 2)
		* (1 + transform.x / transform.y));
	sprite_size.x = ft_ssabs((ssize_t)self->frame_ref->size.y / transform.y)
		* ft_fabs(self->super.transform.scale.x);
	sprite_size.y = ft_ssabs((ssize_t)self->frame_ref->size.y / transform.y)
		* ft_fabs(self->super.transform.scale.y);
	self->start_x = sprite_screen_x - sprite_size.x / 2;
	self->end_x = self->start_x + sprite_size.x;
	self->end_y = self->frame_ref->size.y / 2
		+ ft_ssabs((ssize_t)self->frame_ref->size.y / transform.y) / 2
		+ (ssize_t)self->player_ref->super.transform.rotation.x
		+ (self->player_ref->super.transform.position.z - self->super.transform.position.z)
		* ft_ssabs((ssize_t)self->frame_ref->size.y / transform.y);
	self->start_y = self->end_y - sprite_size.y;
	self->perpendicular_distance = transform.y;
	self->is_visible = transform.y > 0;
}

