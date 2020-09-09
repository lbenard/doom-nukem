/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:38:15 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/08 10:22:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "containers/module.h"
# include "types.h"
# include "sizes/usize.h"
# include "maths/vec2f.h"
# include "maths/vec2d.h"
# include "engine/frame.h"
# include "game/game.h"

/*
** Map element. Contains wall texture for each orientation
*/
typedef struct		s_wall
{
	const t_frame	*texture_ref;
	const t_frame	*overlay_texture_ref;
	t_bool			translucent;
	char			id;
}					t_wall;

t_block_descriptor	*block_from_key(const char key);

/*
** Entity node
*/
typedef struct		s_map_entity_node
{
	t_module	module;
	t_list_head	node;
	const char	*name;
	t_vec2f		pos;
}					t_map_entity_node;

typedef struct		s_map_entity_node_args
{
	const char	*name;
	t_vec2f		pos;
}					t_map_entity_node_args;

t_constructor		map_entity_node(const char *name, const t_vec2f pos);

t_result			init_map_entity_node(t_map_entity_node *const self,
						const t_map_entity_node_args *const args);

t_map_entity_node	*entity_from_name(t_list_head *const self,
						const char *name);

void				destroy_map_entity_node(t_map_entity_node *const self);

void				free_entity_list(t_list_head *const self);

/*
** Map for .wolf level files. Stores textures, blocks (set of 4 textures),
** map size, spawn position and the map itself.
*/
typedef struct		s_map
{
	t_module		module;
	t_list_head		entities;
	t_usize			size;
	t_wall			*map;
	char			floor;
	char			ceiling;
	t_vec2d			spawn;
}					t_map;

typedef struct		s_map_args
{
	const char	*path;
}					t_map_args;

t_constructor		map(const char *const path);

t_result			init_map(t_map *self, const t_map_args *const args);

t_result			map_parse_size(t_map *const self,
						char *size_flag_str);
t_result			map_parse_player(t_map *const self,
						char *player_flag_str);
t_result			map_parse_entities(t_map *const self,
						char *entities_flag_str);
t_result			map_parse_room(t_map *const self,
						char *room_flag_str);
t_result			map_parse_map(t_map *const self,
						char *map_flag_str);

void				destroy_map(t_map *const self);

#endif
