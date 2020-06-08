/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 05:06:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/08 20:07:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"
#include "engine/error.h"

t_result	init_image(t_image *const self, const t_image_args *const args)
{
	sfVector2u	image_size;

	init_module(&self->module);
	if (!(self->image = sfImage_createFromFile(args->path)))
		return (throw_result_str("init_image()", "failed to create image"));
	image_size = sfImage_getSize(self->image);
	self->size.x = image_size.x;
	self->size.y = image_size.y;
	return (OK);
}
