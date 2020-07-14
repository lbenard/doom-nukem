/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_from_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:13:26 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 18:41:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "engine/frame.h"
#include "engine/error.h"
#include "engine/image.h"
#include "engine/render_texture.h"
#include "engine/sprite.h"
#include "ft/mem.h"

static t_result	bmp_fill(int fd, t_frame *bmp, t_u16 bpp)
{
	t_rgba	color;
	size_t	x;
	size_t	y;
	t_rgba	*pixels;

	bpp /= 8;
	y = 0;
	pixels = (t_rgba*)bmp->frame.array;
	while (y < bmp->size.y)
	{
		x = 0;
		while (x < bmp->size.x)
		{
			if (read(fd, &color, bpp) < 0)
				return (throw_result_str(__func__, "read fail"));
			color.c.a = (bpp == 3) ? 255 : color.c.a;
			pixels[x + (bmp->size.y - y - 1) * bmp->size.x].integer =
				color.integer;
			x++;
		}
		lseek(fd, (x * bpp) % 4, SEEK_CUR);
		y++;
	}
	return (OK);
}

static t_result	bmp_parse(int fd, t_frame *self)
{
	t_u32	offset;
	t_u16	bits_per_pixel;
	int		width;
	int		height;

	lseek(fd, sizeof(t_u16) * 4, SEEK_CUR);
	if (read(fd, &offset, sizeof(t_u32)) < 0)
		return (throw_result_str(__func__, "read fail"));
	lseek(fd, sizeof(t_u32), SEEK_CUR);
	if (read(fd, &width, sizeof(t_i32)) < 0)
		return (throw_result_str(__func__, "read fail"));
	if (read(fd, &height, sizeof(t_i32)) < 0)
		return (throw_result_str(__func__, "read fail"));
	self->size = ft_usize((size_t)width, (size_t)height);
	module_add(&self->module, &self->frame,
		array(sizeof(t_u32) * self->size.x * self->size.y));
	if (self->module.has_error)
		return (throw_result_str(__func__, "array module fail"));
	lseek(fd, sizeof(t_u16), SEEK_CUR);
	if (read(fd, &bits_per_pixel, sizeof(t_u16)) < 0)
		return (throw_result_str(__func__, "read fail"));
	lseek(fd, offset, SEEK_SET);
	if (!bmp_fill(fd, self, bits_per_pixel))
		return (throw_result_str(__func__, "bmp_fill fail"));
	return (OK);
}

static t_result	bmp_open(const char *const path, int *const fd)
{
	t_u16	magic;

	if ((*fd = open(path, O_RDONLY, 0)) < 0)
		return (throw_result_str(__func__, "open fail"));
	if (read(*fd, &magic, sizeof(t_u16)) < 0)
	{
		close(*fd);
		return (throw_result_str(__func__, "read fail"));
	}
	if (magic != 0x4d42)
	{
		close(*fd);
		return (throw_result_str(__func__, "unknow file format"));
	}
	return (OK);
}

static void		add_modules(t_frame *const self)
{
	module_add(&self->module, &self->render_texture,
		render_texture(self->size));
	module_add(&self->module, &self->sprite, sprite());
}

t_result		init_frame_from_bmp(t_frame *const self,
					const t_frame_args *const args)
{
	int	fd;

	init_module(&self->module);
	if (!bmp_open(args->path, &fd))
	{
		destroy_frame(self);
		return (throw_result_str(__func__, "failed to load file"));
	}
	if (!bmp_parse(fd, self))
	{
		close(fd);
		return (throw_result_str(__func__, "failed to parse bmp"));
	}
	add_modules(self);
	sfSprite_setTexture(self->sprite.sprite,
		sfRenderTexture_getTexture(self->render_texture.texture), 0);
	if (self->module.has_error == TRUE)
	{
		destroy_frame(self);
		return (throw_result_str("init_frame_from_bmp()",
			"failed to init frame module"));
	}
	self->pixels = (t_rgba*)self->frame.array;
	return (OK);
}
