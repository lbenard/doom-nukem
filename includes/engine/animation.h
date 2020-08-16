/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:55:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 03:14:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "containers/module.h"
# include "engine/spritesheet.h"

typedef struct	s_animation
{
	t_module	module;
	int			anim;
	int			nb_sprite;
	float		speed;
	int			iter;
	float		delta_iter;
}				t_animation;

typedef struct	s_animation_args
{
	int			anim;
	int			nb_sprite;
	float		speed;
}				t_animation_args;

t_constructor	animation(int anim, int nb_sprite, float speed);

t_result		init_animation(t_animation *const self,
					t_animation_args *const args);

void			animation_update(t_animation *const anim,
					const t_spritesheet *const ss);
t_frame			*animation_current(t_animation *const self,
					const t_spritesheet *const ss);

void			destroy_animation(t_animation *const self);

#endif
