/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 23:33:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 02:21:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_ENTITY_H
# define SPRITE_ENTITY_H

# include "engine/entity.h"
# include "maths/vec3f.h"
# include "engine/frame.h"

typedef struct			s_sprite_entity	t_sprite_entity;

typedef struct			s_sprite_entity_vtable
{
	void	(*sprite_entity_update_fn)(struct s_sprite_entity *const self);
}						t_sprite_entity_vtable;

typedef struct			s_sprite_entity
{
	t_entity	super;
	t_frame		texture;
	int			last_start_x;
	int			last_end_x;
	int			last_start_y;
	int			last_end_y;
	float		last_perpendicular_distance;
}						t_sprite_entity;

typedef struct			s_sprite_entity_args
{
	t_vec3f		pos;
	const char	*texture_path;
	t_usize		sprite_size;
}						t_sprite_entity_args;

t_constructor			sprite_entity(const t_vec3f pos,
							const char *texture_path);
t_constructor			sprite_entity_size(const t_vec3f pos,
							const t_usize sprite_size);

t_result				init_sprite_entity(t_sprite_entity *const self,
							t_sprite_entity_args *const args);
t_result				init_sprite_entity_size(t_sprite_entity *const self,
							t_sprite_entity_args *const args);

void					sprite_entity_update(t_sprite_entity *const self);

void					destroy_sprite_entity(t_sprite_entity *const self);

t_sprite_entity_vtable	sprite_entity_vtable(
							void (*sprite_entity_update_fn)(t_sprite_entity*));

#endif