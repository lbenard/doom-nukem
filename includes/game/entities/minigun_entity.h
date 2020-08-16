/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minigun_entity.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:41:43 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 19:17:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIGUN_ENTITY_H
# define MINIGUN_ENTITY_H

# include "game/entities/weapon_entity.h"

typedef struct	s_minigun_entity
{
	t_weapon_entity	super;
	t_animation		animation;
}				t_minigun_entity;

typedef struct	s_minigun_entity_args
{
	t_scene	*scene;
	t_vec2f	pos;
}				t_minigun_entity_args;

t_constructor	minigun_entity(t_scene *const scene, const t_vec2f pos);

t_result		init_minigun_entity(t_minigun_entity *const self,
					t_minigun_entity_args *const args);

void			minigun_entity_update(t_minigun_entity *const self);

void			destroy_minigun_entity(t_minigun_entity *const self);

#endif
