/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:55:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/14 19:49:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "containers/module.h"
# include "engine/spritesheet.h"


/*
typedef struct	s_spritesheet
{
	uint32_t	*pixels;
	uint32_t	**sprite;
	int			nb_sprite;
	int			sheet_w;
	int			sheet_h;
	int			sprite_w;
	int			sprite_h;
	int			sprite_line;
	int			sprite_height;
}				t_spritesheet;
typedef struct	s_animation
{
	int			anim;
	int			nb_sprite;
	float		speed;
	int			frame;
}				t_animation;
*/

typedef struct	s_animation
{
	t_module	module;
	int			anim;
	int			nb_sprite;
	float		speed;
	int			iter;
}				t_animation;

typedef struct	s_animation_args
{
	int			anim;
	int			nb_sprite;
	float		speed;
	int			iter;
}				t_animation_args;


t_constructor	animation(int anim, int nb_sprite, float speed, int iter);

t_result		init_animation(t_animation *const self,
					t_animation_args *const args);

void			animation_update(t_animation *const anim,
					const t_spritesheet *const ss);
t_frame			*animation_current(t_animation *const self,
					t_spritesheet *const ss);

void			destroy_animation(t_animation *const self);

// t_animation	anim;

// module_add(&self->module, &self->anim, animation(0, 42, 1337));

#endif