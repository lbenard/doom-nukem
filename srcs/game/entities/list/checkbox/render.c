/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:19:26 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/11 21:10:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"

void	checkbox_entity_render(t_checkbox_entity *const self,
			t_frame *const frame)
{
	if (self->is_active)
	{
		frame_layer_transform_add(
			frame,
			self->current_texture,
			ft_frame_transform(
				ft_vec2f(0.5f, 0.5f),
				ft_isize(
					self->super.transform.position.x,
					self->super.transform.position.y
				),
				ft_vec2f(
					self->super.transform.scale.x,
					self->super.transform.scale.y
				),
				COLOR_OPAQUE
			)
		);
	}
}
