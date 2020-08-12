/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireball_entity.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:43:50 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/12 14:41:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_ENTITY
# define FIREBALL_ENTITY
# include "game/entities/monster_entity.h"
# include "game/scenes/raycasting_scene.h"

typedef struct	s_fireball_entity
{
	t_sprite_entity		super;
	t_raycasting_scene	*scene;
	const t_map			*map_ref;
	int					damage;
}				t_fireball_entity;

typedef struct	s_fireball_entity_args
{
	t_vec3f					pos;
	t_vec3f					direction;
}				t_fireball_entity_args;

t_constructor	fireball_entity(const t_vec3f pos, const t_vec3f direction);

t_result		init_fireball_entity(t_fireball_entity *const self,
					const t_fireball_entity_args *const args);

void			fireball_entity_update(t_fireball_entity *const self);

void			destroy_fireball_entity(t_fireball_entity *const self);

void			render_fireball_entity(t_fireball_entity *const self, t_frame *fb);

#endif