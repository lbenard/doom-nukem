/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:58:51 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/12 19:03:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/error.h"
#include "sizes/usize.h"
#include "engine/spritesheet.h"

static void	grab_sprite(t_spritesheet *ss, int num)
{
	t_usize	i;
	size_t	x;
	size_t	startx;
	size_t	starty;

	startx = (num * ss->sprite_size.x) % ss->sheet_size.x;
	starty = (num / ss->grid_size.x) * ss->sprite_size.y;
	x = 0;
	i.y = 0;
	while (i.y < ss->sprite_size.y)
	{
		i.x = 0;
		while (i.x < ss->sprite_size.x)
		{
			ss->sprite[num].pixels[x] = ss->pixels.pixels[startx + i.x
				+ (i.y + starty) * (ss->sheet_size.x)];
			i.x++;
			x++;
		}
		i.y++;
	}
}

t_result		init_spritesheet(t_spritesheet *const self,
					t_spritesheet_args *const args)
{
	size_t	i;

	init_module(&self->module);
	self->sprite = NULL;
	module_add(&self->module, &self->pixels, frame_from_file(args->path));
	if (self->module.has_error)
	{
		destroy_spritesheet(self);
		return (throw_result_str("init_spritesheet()",
			"failed to init spritesheet"));
	}
	self->grid_size = args->grid_size;
	self->nb_sprite = args->grid_size.x * args->grid_size.y;
	self->sheet_size = self->pixels.size;
	self->sprite_size = ft_usize(self->pixels.size.x / self->grid_size.x,
		self->pixels.size.y / self->grid_size.y);
	if (!(self->sprite = (t_frame*)malloc(sizeof(t_frame) * (self->nb_sprite))))
	{
		destroy_spritesheet(self);
		return (throw_result_str("init_spritesheet()",
			"failed to malloc sprite"));
	}
	i = 0;
	while (i < self->nb_sprite)
	{
		module_add(&self->module, &self->sprite[i],
			frame(self->sprite_size, ft_rgba(0, 0, 0, 255)));
		if (!self->module.has_error)
			grab_sprite(self, i);
		i++;
	}
	if (self->module.has_error)
	{
		destroy_spritesheet(self);
		return (throw_result_str("init_spritesheet()",
			"failed to create sprites"));
	}
	return (OK);
}
