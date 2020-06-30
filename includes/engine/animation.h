/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:55:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 20:05:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "containers/module.h"

typedef struct	s_animation
{
	t_module	module;
	int			anim;
	float		speed;
}				t_animation;

typedef struct	s_animation_entity_args
{
	int			anim;
	float		speed;
}				t_animation_entity_args;

t_co

t_result		init_animation(t_animation *self, int anim, float speed);


#endif