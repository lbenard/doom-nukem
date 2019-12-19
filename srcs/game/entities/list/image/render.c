/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:54:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/29 18:21:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/image_entity.h"

void	image_entity_render(t_image_entity *const self, t_frame	*const frame)
{
	frame_layer_transform(frame, &self->image, self->transform, blend_add);
}
