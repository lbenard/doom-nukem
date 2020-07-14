/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:54:30 by mribouch          #+#    #+#             */
/*   Updated: 2020/07/14 19:49:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/animation.h"
#include "engine/spritesheet.h"

t_result		init_animation(t_animation *const self,
				t_animation_args *const args)
{
	init_module(&self->module);
	self->anim = args->anim;
	self->nb_sprite = args->nb_sprite;
	self->speed = args->speed;
	self->iter = 0;
	return (OK);
}

void			destroy_animation(t_animation *const self)
{
	destroy_module(&self->module);
}

t_constructor	animation(int anim, int nb_sprite, float speed, int iter)
{
	static t_animation_args	args;

	args.anim = anim;
	args.nb_sprite = nb_sprite;
	args.speed = speed;
	args.iter = iter;

	return (ft_constructor(init_animation, destroy_animation,
		sizeof(t_animation), &args));
}

void			animation_update(t_animation *const anim, const t_spritesheet *const ss)
{
	anim->iter++;
	if (anim->iter * anim->speed >= ss->sprite_line)
		anim->iter = 0;
}

t_frame	*animation_current(t_animation *const self, t_spritesheet *const ss)
{
	int	line;

	line = ss->sprite_line * self->anim;
	return (&ss->sprite[(int)(line + self->iter * self->speed)]);
}