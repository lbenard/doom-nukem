/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:13:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/07 18:34:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/frame.h"
#include "engine/error.h"
#include "engine/image.h"
#include "engine/render_texture.h"
#include "engine/sprite.h"
#include "ft/mem.h"

static t_result	load_texture(t_image *const file,
					const t_frame_args *const args)
{
	if (static_module_create(file, image(args->path)) == ERROR)
	{
		return (throw_result_str("init_frame_from_file()",
			"cannot load texture path"));
	}
	if (file->size.x == 0 || file->size.y == 0)
	{
		destroy_image(file);
		return (throw_result_str("init_frame_from_file()",
			"cannot create a frame with null horizontal or vertical size"));
	}
	return (OK);
}

static void		add_modules(t_frame *const self)
{
	module_add(&self->module, &self->frame,
		array(sizeof(t_u32) * self->size.x * self->size.y));
	module_add(&self->module, &self->render_texture,
		render_texture(self->size));
	module_add(&self->module, &self->sprite, sprite());
}

static void		copy_texture(t_frame *const self, t_image *const file)
{
	ft_memcpy(self->frame.array, sfImage_getPixelsPtr(file->image),
		self->frame.size);
	sfSprite_setTexture(self->sprite.sprite,
		sfRenderTexture_getTexture(self->render_texture.texture), 0);
}

t_result		init_frame_from_file(t_frame *const self,
					const t_frame_args *const args)
{
	t_image	file;

	init_module(&self->module);
	if (load_texture(&file, args) == ERROR)
		return (throw_result_str("init_frame_from_file()", "failed to load"));
	self->size = file.size;
	add_modules(self);
	if (self->module.has_error == TRUE)
	{
		destroy_image(&file);
		destroy_frame(self);
		return (throw_result_str("init_frame_from_file()",
			"failed to init frame module"));
	}
	copy_texture(self, &file);
	destroy_image(&file);
	return (OK);
}
