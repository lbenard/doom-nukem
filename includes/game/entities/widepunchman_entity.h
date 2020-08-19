/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widepunchman_entity.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 02:06:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 01:12:35 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDEPUNCHMAN_ENTITY_H
# define WIDEPUNCHMAN_ENTITY_H

# include "game/entities/monster_entity.h"
# include "engine/animation.h"

typedef struct	s_widepunchman_entity
{
	t_monster_entity	super;
	t_bool				is_moving;
	double				last_shot;
	int					count_fireball;
	float				speed;
}				t_widepunchman_entity;

typedef struct	s_widepunchman_entity_args
{
	t_scene	*scene;
	t_vec2f	pos;
}				t_widepunchman_entity_args;

t_constructor	widepunchman_entity(t_scene *const scene, const t_vec2f pos);

t_result		init_widepunchman_entity(t_widepunchman_entity *const self,
					const t_widepunchman_entity_args *const args);

void			widepunchman_entity_update(t_widepunchman_entity *const self);

void			destroy_widepunchman_entity(t_widepunchman_entity *const self);

#endif
