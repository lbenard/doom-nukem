/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_entity.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:32:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/30 14:09:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_ENTITY_H
# define ELEMENT_ENTITY_H

# include "engine/entity.h"
# include "types.h"
# include "maths/vec2i.h"

typedef struct	s_map_block
{
	t_bool					is_visible;
	t_bool					is_collideable;
	float					height;
	enum					e_block_type
	{
		CUBE,
		DOOR,
		ANGLE,
		PILLAR
	}						type;
	struct	s_cube_type 	cube;
	struct	s_door_type
	{
		enum	e_orientation
		{
			NORTH,
			EAST,
			SOUTH,
			WEST
		}		orientation;
		float	opening;
	}						door;
	struct	s_angle_type
	{
		enum	e_orientation
		{
			NORTH_WEST,
			NORTH_EAST,
			SOUTH_EAST,
			SOUTH_WEST
		}		orientation;
	}						angle;
	struct	s_pillar_type	pillar;
}				t_map_block;

typedef struct		s_map_entity
{
	t_entity	super;
	t_vec2i		spawn_pos;
}					t_map_entity;

typedef struct		s_map_entity_args
{
	const char	*map_path;
}					t_map_entity_args;

t_smodule_factory	map_entity(const t_map_entity_args *const args);

#endif