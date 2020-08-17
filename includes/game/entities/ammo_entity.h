/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo_entity.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:31:10 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 21:47:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMMO_ENTITY_H
# define AMMO_ENTITY_H

# include "game/entities/sprite_entity.h"

typedef struct	s_ammo_entity
{
	t_sprite_entity	super;
}				t_ammo_entity;

typedef struct	s_ammo_entity_args
{
	t_scene	*scene;
	t_vec2f	pos;
}				t_ammo_entity_args;

t_constructor	ammo_entity(t_scene *const scene, const t_vec2f pos);

t_result		init_ammo_entity(t_ammo_entity *const self,
					t_ammo_entity_args *const args);

void			ammo_entity_update(t_ammo_entity *const self);

void			destroy_ammo_entity(t_ammo_entity *const self);

#endif
