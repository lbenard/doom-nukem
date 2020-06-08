/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:46:10 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/05 02:01:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/camera_entity.h"
#include "engine/error.h"

t_result	init_camera_entity(t_camera_entity *const self,
				const t_camera_entity_args *const args)
{
	init_entity_default(&self->super, entity_vtable(camera_entity_update));
	self->super.transform.position.x = args->spawn_pos.x;
	self->super.transform.position.y = args->spawn_pos.y;
	self->super.transform.rotation.y = args->direction;
	module_add(&self->super.module, &self->input, input());
	if (self->super.module.has_error)
	{
		destroy_camera_entity(self);
		return (throw_result_str("init_camera_entity()",
			"failed to init new camera entity"));
	}
	return (OK);
}
