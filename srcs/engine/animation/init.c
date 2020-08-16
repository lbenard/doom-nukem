/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:53:40 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 03:14:31 by lbenard          ###   ########.fr       */
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
	self->delta_iter = 0.0f;
	return (OK);
}
