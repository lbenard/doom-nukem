/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:54:30 by mribouch          #+#    #+#             */
/*   Updated: 2020/07/08 20:46:54 by mribouch         ###   ########.fr       */
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

void			animate_sprite(t_animation *anim, t_spritesheet *ss,
					t_frame *screen, int x, int y, float coef)
{
	int	line;

(void)coef;
	line = ss->sprite_line * anim->anim;
	frame_layer_transform(screen,
		&ss->sprite[(int)(line + anim->iter * anim->speed)],
		ft_frame_transform(ft_vec2f(0.0f, 0.0f),
			ft_isize(x, y),
			ft_vec2f(coef, coef),
			255),
		blend_add);
	anim->iter++;
	if (anim->iter * anim->speed >= ss->sprite_line)
		anim->iter = 0;
	// printf("iter = %d\n", anim->iter);
}