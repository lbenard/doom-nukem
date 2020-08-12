/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:54:30 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/12 18:56:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/animation.h"

t_constructor	animation(int anim, int nb_sprite, float speed)
{
	static t_animation_args	args;

	args.anim = anim;
	args.nb_sprite = nb_sprite;
	args.speed = speed;
	return (ft_constructor(init_animation, destroy_animation,
		sizeof(t_animation), &args));
}
