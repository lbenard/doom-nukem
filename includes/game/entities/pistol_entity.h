/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pistol_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:41:43 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/09 23:58:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PISTOL_ENTITY_H
# define PISTOL_ENTITY_H

# include "game/entities/weapon_entity.h"

typedef struct	s_pistol_entity
{
	t_weapon_entity	super;
	t_animation		animation;
}				t_pistol_entity;

typedef struct	s_pistol_entity_args
{
	t_scene	*scene;
	t_vec2f	pos;
}				t_pistol_entity_args;

t_constructor	pistol_entity(t_scene *const scene, const t_vec2f pos);

t_result		init_pistol_entity(t_pistol_entity *const self,
					t_pistol_entity_args *const args);

void			pistol_entity_update(t_pistol_entity *const self);

void			destroy_pistol_entity(t_pistol_entity *const self);

#endif
