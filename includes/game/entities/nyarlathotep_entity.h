/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nyarlathotep_entity.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 00:50:39 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/07 01:40:05 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NYARLATHOTEP_ENTITY
# define NYARLATHOTEP_ENTITY

#include "game/entities/monster_entity.h"

typedef struct			s_nyarlathotep_entity
{
	t_monster_entity	super;
}						t_nyarlathotep_entity;

typedef struct			s_nyarlathotep_entity_args
{
	t_scene				*scene;
	t_vec2f				pos;
}						t_nyarlathotep_entity_args;

t_constructor			nyarlathotep_entity(t_scene *const scene,
	const t_vec2f pos);

t_result				init_nyarlathotep_entity(
	t_nyarlathotep_entity *const self, const t_nyarlathotep_entity_args *const
		args);

void					nyarlathotep_entity_update(
	t_nyarlathotep_entity *const self);

void					destroy_nyarlathotep_entity(
	t_nyarlathotep_entity *const self);

#endif