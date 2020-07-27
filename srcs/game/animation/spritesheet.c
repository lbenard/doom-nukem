/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritesheet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:54:37 by mribouch          #+#    #+#             */
/*   Updated: 2020/07/26 22:23:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/spritesheet.h"
#include "engine/error.h"
#include "engine/animation.h"
#include "ft/io.h"
#include <stdlib.h>

void		grab_sprite(t_spritesheet *ss, int num)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	startx;
	size_t	starty;

	startx = num * ss->sprite_size.x;
	startx %= ss->sheet_size.x;
	starty = (num / ss->grid_size.x) * ss->sprite_size.y;
	x = 0;
	i = 0;
	while (i < ss->sprite_size.y)
	{
		j = 0;
		while (j < ss->sprite_size.x)
		{
			ss->sprite[num].pixels[x] = ss->pixels.pixels[startx + j
				+ (i + starty) * (ss->sheet_size.x)];
			j++;
			x++;
		}
		i++;
	}
}

t_result		init_spritesheet(t_spritesheet *const self,
					t_spritesheet_args *const args)
{
	size_t	i;

	init_module(&self->module);
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
		i++;
	}
	if (self->module.has_error)
	{
		destroy_spritesheet(self);
		return (throw_result_str("init_spritesheet()",
			"failed to create sprites"));
	}
	i = 0;
	while (i < self->nb_sprite)
	{
		grab_sprite(self, i);
		i++;
	}
	return (OK);
}

void	destroy_spritesheet(t_spritesheet *const self)
{
	destroy_module(&self->module);
	free(self->sprite);
}

t_constructor	spritesheet(const char *const path, const t_usize grid_size)
{
	static t_spritesheet_args	args;

	args.path = path;
	args.grid_size = grid_size;
	return (ft_constructor(init_spritesheet, destroy_spritesheet,
			sizeof(t_spritesheet), &args));
}