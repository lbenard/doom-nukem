/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_entity.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:07:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/14 17:54:45 by mribouch         ###   ########.fr       */
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

typedef struct s_raycasting_scene	t_raycasting_scene;

typedef struct	s_monster_entity
{
	t_sprite_entity			super;
	t_animation				animation;
	const t_spritesheet		*spritesheet_ref;
	t_player_entity			*player_ref;
	float					full_health;
	float					health;
	float					damage;
	const char				*name;
	int						distance_agro;
	int						max_distance_agro;
	t_star					a_star;
	t_bool					is_star;
	t_bool					agro;
	double					last_damage;
	t_text					name_text;
}				t_monster_entity;

typedef struct	s_monster_entity_args
{
	t_vec2f					pos;
	float					health;
	int						damage;
	const char				*name;
	const t_spritesheet		*spritesheet_ref;
	t_raycasting_scene		*ctx;
}				t_monster_entity_args;

typedef struct	s_monster_stats
{
	t_vec2f		pos;
	float		health;
	float		damage;
	const char	*name;
}				t_monster_stats;

t_monster_stats	ft_monster_stats(const t_vec2f pos,
					const float health,
					const float damage,
					const char *name);

t_constructor	monster_entity(const t_monster_stats stats,
					const t_spritesheet *const spritesheet_ref,
					t_raycasting_scene *const ctx);

t_result		init_monster_entity(t_monster_entity *const self,
					const t_monster_entity_args *const args);

void			monster_entity_update(t_monster_entity *const self);
int				distance_monster_player(t_monster_entity *self);
void			update_agro_distance(t_monster_entity *self);
float				get_distance_vec(t_vec3f source, t_vec3f target);
int				get_orientate_sprite(t_monster_entity *self);
void			a_star_attack(t_monster_entity *self,
					int distance,
					float speed);
void			agro_if_take_damage(t_monster_entity *self);

void			destroy_monster_entity(t_monster_entity *const self);

#endif
