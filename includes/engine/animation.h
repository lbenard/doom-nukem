/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:55:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/08 20:46:37 by mribouch         ###   ########.fr       */
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


t_result		init_animation(t_animation *const self,
					t_animation_args *const args);
void			destroy_animation(t_animation *const self);
t_constructor	animation(int anim, int nb_sprite, float speed, int iter);
void		animate_sprite(t_animation *anim, t_spritesheet *ss, t_frame *screen, int x, int y, float coef);


// t_animation	anim;

// module_add(&self->module, &self->anim, animation(0, 42, 1337));

#endif