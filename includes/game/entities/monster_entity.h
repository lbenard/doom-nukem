/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_entity.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:07:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/19 21:39:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_ENTITY_H
# define MONSTER_ENTITY_H

# include "game/entities/sprite_entity.h"
# include "engine/frame.h"

typedef struct	s_monster_entity
{
	t_sprite_entity	super;
	float			health;
	int				damage;
}				t_monster_entity;

typedef struct	s_monster_entity_args
{
	float	health;
	int		damage;
	t_vec2f	pos;
	char	*path;
}				t_monster_entity_args;

t_constructor	monster_entity(const float health,
					const int damage,
					const t_vec2f pos,
					char *const path);

t_result		init_monster_entity(t_monster_entity *const self,
					const t_monster_entity_args *const args);

void			monster_entity_update(t_sprite_entity *const self);
// void			monster_entity_render(t_monster_entity *const self,
// 					t_frame *const fb);

void			destroy_monster_entity(t_monster_entity *const self);

#endif