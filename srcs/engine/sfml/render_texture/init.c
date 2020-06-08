/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:56:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/05 01:59:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "engine/render_texture.h"

t_result	init_render_texture(t_render_texture *const self,
				const t_render_texture_args *const args)
{
	init_module(&self->module);
	if (!(self->texture =
		sfRenderTexture_create(args->size.x, args->size.y, 0)))
	{
		return (throw_result_str("new_render_texture()",
			"failed to create new render texture"));
	}
	self->size = args->size;
	return (OK);
}
