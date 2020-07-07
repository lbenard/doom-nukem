/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritesheet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:54:37 by mribouch          #+#    #+#             */
/*   Updated: 2020/07/07 21:02:28 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/spritesheet.h"
#include "engine/error.h"
#include "engine/animation.h"
	// frame_layer(NULL, &self->pixels, ft_isize(0, 0), blend_add);

void		animate_sprite(t_animation *anim, t_spritesheet *ss, t_frame *screen, int x, int y, int coef)
{
	int	line;
	int	index;

	line = ss->sprite_line * anim->anim;
	frame_layer(screen, ss->sprite[(int)(line + anim->iter * anim->speed)].pixels, ft_isize(0, 0), blend_add);
	anim->iter++;
	if (anim->iter * anim->speed >= ss->sprite_line)
		anim->iter = 0;
	// printf("iter = %d\n", anim->iter);
}

void		grab_sprite(t_spritesheet *ss, int num)
{
	int	i;
	int	j;
	int	x;
	// int	y;
	int	startx;
	int	starty;
	int	size;
	int	index;

	i = 0;
	j = 0;
	x = 0;
	// y = 0;
	startx = num * ss->sprite_w;
	startx %= ss->sheet_w;
	starty = (num / ss->sprite_line) * ss->sprite_h;
	while (i < ss->sprite_h)
	{
		while (j < ss->sprite_w)
		{
			index = startx + j + (i + starty) * (ss->sheet_w);
			ss->sprite[i].pixels[x] = ss->pixels.pixels[index];
			// ss->sprite[num][x] = ss->pixels[index];
			j++;
			x++;
		}
		j = 0;
		i++;
	}
}

t_result		init_spritesheet(t_spritesheet *const self,
					t_spritesheet_args *const args)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	init_module(&self->module);
	module_add(&self->module, &self->pixels, frame_from_bmp(args->path));
	if (self->module.has_error)
	{
		destroy_spritesheet(self);
		return (throw_result_str("init_spritesheet()",
			"failed to init spritesheet"));
	}
	self->sprite_line = args->line;
	self->sprite_height = args->height;
	self->sheet_w = self->pixels.size.x;
	self->sheet_h = self->pixels.size.y;
	self->sprite_w = self->pixels.size.x / args->line;
	self->sprite_h = self->pixels.size.y / args->height;
	if (!(self->sprite = malloc(sizeof(t_frame) * (args->nb_sprite))))
		return (throw_result_str("load_spritesheet", "failed to malloc sprite"));
	while (i < args->nb_sprite)
	{
		module_add(&self->module, &self->sprite[i],
			frame(ft_usize(self->pixels.size.x / args->line,
				self->pixels.size.y / args->height), ft_rgba(0, 0, 0, 255)));
		i++;
	}
	i = 0;
	while (i < args->nb_sprite)
	{
		grab_sprite(&self, i);
		i++;
	}
}

void	destroy_spritesheet(t_spritesheet *const self)
{
	destroy_module(&self->module);
}

t_constructor	spritesheet(char *path, int nb_sprite, int line, int height)
{
	static t_spritesheet_args	args;

	args.path = path;
	args.nb_sprite = nb_sprite;
	args.line = line;
	args.height = height;

	return (ft_constructor(init_spritesheet, destroy_spritesheet,
			sizeof(t_spritesheet), &args));
}