/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_from_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:50:31 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:24:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/image_entity.h"
#include "engine/error.h"

t_image_entity	*new_image_entity_from_file(
					const t_image_entity_args *const args)
{
	t_image_entity	*ret;

	if (!(ret = (t_image_entity*)malloc(sizeof(t_image_entity))))
	{
		return (throw_error_str("new_image_entity_from_file()",
			"failed while allocating new image entity"));
	}
	init_classic_entity_default(&ret->super, image_entity_update);
	module_add_smodule(&ret->super.module, frame_from_file(args->path),
		&ret->image);
	if (ret->super.module.has_error)
	{
		free_image_entity(ret);
		return (throw_error_str("new_image_entity_from_file()",
			"failed while creating new image entity"));
	}
	return (ret);
}
