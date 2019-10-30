/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:30:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/22 16:31:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/button_entity.h"

void	button_entity_render(t_button_entity *const self, t_frame *const frame)
{
	frame_layer(frame,
		self->current_texture,
		ft_isize(
			self->super.transform.position.x,
			self->super.transform.position.y),
		blend_add);
}
