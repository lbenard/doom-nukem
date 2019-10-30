/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:31:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/26 22:26:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/frame.h"
#include "engine/sprite.h"
#include "engine/render_texture.h"
#include "engine/error.h"

static void	add_modules(t_frame *const self, const t_frame_args *const args)
{
	module_add_smodule(&self->module,
		array(sizeof(t_u32) * args->size.x * args->size.y), &self->frame);
	module_add_hmodule(&self->module,
		render_texture(args->size), (void**)&self->render_texture);
	module_add_hmodule(&self->module, sprite(), (void**)&self->sprite);
}

t_result	init_frame(t_frame *const self, const t_frame_args *const args)
{
	init_module(&self->module);
	if (args->size.x == 0 || args->size.y == 0)
	{
		return (throw_result_str("init_frame()",
			"cannot create a frame with null horizontal or vertical size"));
	}
	add_modules(self, args);
	*(t_usize*)&self->size = args->size;
	if (self->module.has_error == FALSE)
	{
		frame_fill(self, args->fill_color);
		sfSprite_setTexture(self->sprite,
			sfRenderTexture_getTexture(self->render_texture), 0);
	}
	else
	{
		destroy_frame(self);
		return (throw_result_str("init_frame()",
			"failed to init frame module"));
	}
	return (OK);
}
