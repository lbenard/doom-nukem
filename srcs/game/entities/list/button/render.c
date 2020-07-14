/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:30:43 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/11 21:03:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/button_entity.h"

void	button_entity_render(t_button_entity *const self, t_frame *const frame)
{
	frame_layer_add(frame,
		self->current_texture,
		ft_isize(
			self->super.transform.position.x,
			self->super.transform.position.y));
}
