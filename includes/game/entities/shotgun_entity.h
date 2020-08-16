/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shotgun_entity.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 02:41:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 02:43:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOTGUN_ENTITY_H
# define SHOTGUN_ENTITY_H

# include "game/entities/weapon_entity.h"

typedef struct	s_shotgun_entity
{
	t_weapon_entity	super;
	t_animation		animation;
}				t_shotgun_entity;

typedef struct	s_shotgun_entity_args
{
	t_scene	*scene;
	t_vec2f	pos;
}				t_shotgun_entity_args;

t_constructor	shotgun_entity(t_scene *const scene, const t_vec2f pos);

t_result		init_shotgun_entity(t_shotgun_entity *const self,
					t_shotgun_entity_args *const args);

void			shotgun_entity_update(t_shotgun_entity *const self);

void			destroy_shotgun_entity(t_shotgun_entity *const self);

#endif
