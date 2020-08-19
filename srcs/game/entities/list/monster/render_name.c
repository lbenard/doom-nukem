/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 03:37:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 03:39:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"

void	monster_entity_render_name(const t_monster_entity *const self,
			t_frame *const fb,
			const float distance_opacity)
{
	frame_layer_transform_add(fb,
		&self->name_text.target,
		ft_frame_transform(ft_vec2f(0.5f, 1.0f),
			ft_isize((self->super.start_x + self->super.end_x) / 2,
				self->super.start_y),
			ft_vec2f(10.0f / self->super.perpendicular_distance
				* self->super.super.transform.scale.x,
				10.0f / self->super.perpendicular_distance
				* self->super.super.transform.scale.y),
			distance_opacity));
}
