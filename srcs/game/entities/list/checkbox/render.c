/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:19:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/14 19:12:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"

void	checkbox_entity_render(t_checkbox_entity *const self,
			t_frame *const frame)
{
	frame_layer(frame,
		self->current_texture,
		ft_isize(
			self->super.transform.position.x,
			self->super.transform.position.y),
		blend_add);
}
