/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 23:33:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/20 19:20:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_ENTITY_H
# define SPRITE_ENTITY_H

# include "engine/entity.h"
# include "maths/vec3f.h"
# include "engine/frame.h"
# include "game/entities/player_entity.h"

typedef struct			s_sprite_entity	t_sprite_entity;

typedef struct			s_sprite_entity_vtable
{
	void	(*sprite_entity_update_fn)(struct s_sprite_entity *const self);
}						t_sprite_entity_vtable;

typedef struct			s_sprite_entity
{
	t_entity				super;
	t_frame					texture;
	const t_player_entity	*player_ref;
	const t_frame			*frame_ref;
	int						start_x;
	int						end_x;
	int						start_y;
	int						end_y;
	float					perpendicular_distance;
	t_bool					is_visible;
}						t_sprite_entity;

typedef struct			s_sprite_entity_args
{
	t_vec3f					pos;
	const char				*texture_path;
	t_usize					sprite_size;
	const t_player_entity	*player_ref;
	const t_frame			*frame_ref;
}						t_sprite_entity_args;

t_constructor			sprite_entity(const t_vec3f pos,
							const char *texture_path,
							const t_player_entity *const player_ref,
							const t_frame *const frame_ref);
t_constructor			sprite_entity_size(const t_vec3f pos,
							const t_usize sprite_size,
							const t_player_entity *const player_ref,
							const t_frame *const frame_ref);

t_result				init_sprite_entity(t_sprite_entity *const self,
							t_sprite_entity_args *const args);
t_result				init_sprite_entity_size(t_sprite_entity *const self,
							t_sprite_entity_args *const args);

void					sprite_entity_update(t_sprite_entity *const self);

void					destroy_sprite_entity(t_sprite_entity *const self);

t_sprite_entity_vtable	sprite_entity_vtable(
							void (*sprite_entity_update_fn)(t_sprite_entity*));

#endif