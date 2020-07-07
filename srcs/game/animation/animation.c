/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:54:30 by mribouch          #+#    #+#             */
/*   Updated: 2020/07/07 21:02:30 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/animation.h"

t_result	init_animation(t_animation *const self,
				t_animation_args *const args)
{
	init_module(&self->module);
	self->anim = args->anim;
	self->nb_sprite = args->nb_sprite;
	self->speed = args->speed;
	self->iter = 0;
	return (OK);
}

void		destroy_animation(t_animation *const self)
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
