/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:54:30 by mribouch          #+#    #+#             */
/*   Updated: 2020/07/02 21:12:48 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/animation.h"

t_result	init_animation(t_animation *const self, int anim, int nb_sprite,
								float speed)
{
	init_module(&self->module);
	self->anim = anim;
	self->nb_sprite = nb_sprite;
	self->speed = speed;
	self->iter = 0;
	return (OK);
}

void		destroy_animation(t_animation *const self)
{
	destroy_module(&self->module);
}

t_constructor	animation(void)
{
	return (ft_constructor(init_animation, destroy_animation,
		sizeof(t_animation), NULL));
}
