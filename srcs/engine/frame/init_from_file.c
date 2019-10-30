/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:13:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/26 22:28:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/frame.h"
#include "engine/error.h"
#include "engine/image.h"
#include "engine/render_texture.h"
#include "engine/sprite.h"
#include "ft/mem.h"

static t_result	load_texture(t_image **file, t_usize *image_size,
					const t_frame_args *const args)
{
	sfVector2u	frame_size;

	if (!(*file = sfImage_createFromFile(args->path)))
	{
		return (throw_result_str("init_frame_from_file()",
			"cannot load texture path"));
	}
	frame_size = sfImage_getSize(*file);
	if (frame_size.x == 0 || frame_size.y == 0)
	{
		sfImage_destroy(*file);
		return (throw_result_str("init_frame_from_file()",
			"cannot create a frame with null horizontal or vertical size"));
	}
	*image_size = ft_usize(frame_size.x, frame_size.y);
	return (OK);
}

static void		add_modules(t_frame *const self)
{
	module_add_smodule(&self->module,
		array(sizeof(t_u32) * self->size.x * self->size.y), &self->frame);
	module_add_hmodule(&self->module, render_texture(self->size),
		(void**)&self->render_texture);
	module_add_hmodule(&self->module, sprite(), (void**)&self->sprite);
}

static void		copy_texture(t_frame *const self, t_image *const file)
{
	ft_memcpy(self->frame.array, sfImage_getPixelsPtr(file), self->frame.size);
	sfSprite_setTexture(self->sprite,
		sfRenderTexture_getTexture(self->render_texture), 0);
}

t_result		init_frame_from_file(t_frame *const self,
					const t_frame_args *const args)
{
	t_image	*file;

	init_module(&self->module);
	if (load_texture(&file, &self->size, args) == ERROR)
		return (throw_result_str("init_frame_from_file()", "failed to load"));
	add_modules(self);
	if (self->module.has_error == TRUE)
	{
		sfImage_destroy(file);
		destroy_frame(self);
		return (throw_result_str("init_frame_from_file()",
			"failed to init frame module"));
	}
	copy_texture(self, file);
	sfImage_destroy(file);
	return (OK);
}
