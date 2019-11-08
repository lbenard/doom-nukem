/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:50:31 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:33:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/image_entity.h"
#include "engine/error.h"

t_result	init_image_entity_from_file(t_image_entity *const self,
				const t_image_entity_args *const args)
{
	init_classic_entity_default(&self->super, image_entity_update);
	module_add(&self->super.module, &self->image, frame_from_file(args->path));
	if (self->super.module.has_error)
	{
		destroy_image_entity(self);
		return (throw_result_str("init_image_entity_from_file()",
			"failed while creating new image entity"));
	}
	return (OK);
}
