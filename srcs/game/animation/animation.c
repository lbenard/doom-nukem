/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:54:30 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/04 01:07:42 by mribouch         ###   ########.fr       */
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

t_constructor	animation(int anim, int nb_sprite, float speed)
{
	static t_animation_args	args;

	args.anim = anim;
	args.nb_sprite = nb_sprite;
	args.speed = speed;
	return (ft_constructor(init_animation, destroy_animation,
		sizeof(t_animation), &args));
}

void			animation_update(t_animation *const anim,
	const t_spritesheet *const ss)
{
	anim->iter++;
	if ((size_t)(anim->iter * anim->speed) >= ss->grid_size.x)
		anim->iter = 0;
}

t_frame	*animation_current(t_animation *const self,
			const t_spritesheet *const ss)
{
	int	line;

	line = ss->grid_size.x * self->anim;
	return (&ss->sprite[(int)(line + self->iter * self->speed)]);
}