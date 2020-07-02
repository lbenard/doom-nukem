/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:55:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/02 19:32:20 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "containers/module.h"


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

typedef struct	s_animation_entity_args
{
	int			anim;
	int			nb_sprite;
	float		speed;
	int			iter;
}				t_animation_entity_args;


t_result		init_animation(t_animation *const self, int anim, int nb_sprite, float speed);
void			destroy_animation(t_animation *const self);
t_constructor	animation(void);

#endif