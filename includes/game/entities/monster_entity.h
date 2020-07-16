/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_entity.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:07:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 20:37:03 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONSTER_ENTITY_H
# define MONSTER_ENTITY_H

# include "game/entities/sprite_entity.h"
# include "engine/frame.h"
# include "engine/animation.h"
# include "engine/spritesheet.h"
# include "engine/text.h"
# include "game/entities/player_entity.h"
# include "engine/a_star.h"

typedef struct	s_monster_entity
{
	t_sprite_entity			super;
	t_animation				animation;
	const t_spritesheet		*spritesheet_ref;
	const t_player_entity	*player_ref;
	float					health;
	float					damage;
	const char				*name;
	t_star					a_star;
	t_bool					is_star;
	t_text					name_text;
}				t_monster_entity;

typedef struct	s_monster_entity_args
{
	t_vec2f					pos;
	const t_spritesheet		*spritesheet_ref;
	const t_player_entity	*player_ref;
	float					health;
	int						damage;
	const char				*name;
}				t_monster_entity_args;

t_constructor	monster_entity(const t_vec2f pos,
					const t_spritesheet *const spritesheet_ref,
					const t_player_entity *const player_ref,
					const float health,
					const float damage,
					const char *const name);

t_result		init_monster_entity(t_monster_entity *const self,
					const t_monster_entity_args *const args);

void			monster_entity_update(t_monster_entity *const self);
// void			monster_entity_render(t_monster_entity *const self,
// 					t_frame *const fb);

void			destroy_monster_entity(t_monster_entity *const self);

#endif