/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:38:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:58:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "containers/module.h"
# include "types.h"
# include "sizes/usize.h"
# include "maths/vec2f.h"
# include "maths/vec2d.h"
# include "engine/image.h"

/*
** Map element. Contains wall texture for each orientation
*/
typedef struct	s_wall
{
	const t_image	*north_texture_ref;
	const t_image	*east_texture_ref;
	const t_image	*south_texture_ref;
	const t_image	*west_texture_ref;
}				t_wall;

/*
** Texture node
*/
typedef struct	s_texture_node
{
	t_list_head	node;
	const char	*key;
	t_image		image;
}				t_texture_node;

typedef struct	s_texture_node_args
{
	const char	*key;
	const char	*path;
}				t_texture_node_args;

t_constructor	texture_node(const char *key, const char *path);

t_result		init_texture_node(t_texture_node *const self,
					const t_texture_node_args *const args);

t_texture_node	*texture_from_key(t_list_head *const self,
					const char *const key);

void			destroy_texture_node(t_texture_node *const self);

void			free_texture_list(t_list_head *const self);

/*
** Block node
*/
typedef struct	s_block_node
{
	t_list_head	node;
	char		key;
	const char	*north_texture_name;
	const char	*east_texture_name;
	const char	*south_texture_name;
	const char	*west_texture_name;
}				t_block_node;

typedef struct	s_block_node_args
{
	const char	*key;
	char		**values;
}				t_block_node_args;

t_constructor	block_node(const char *key, char **values);

t_result		init_block_node(t_block_node *const self,
					const t_block_node_args *const args);

t_block_node	*block_from_key(t_list_head *const self,
					const char key);

void			destroy_block_node(t_block_node *const self);

void			free_block_list(t_list_head *const self);

/*
** Map for .wolf level files. Stores textures, blocks (set of 4 textures),
** map size, spawn position and the map itself.
*/
typedef struct	s_map
{
	t_module	module;
	t_list_head textures;
	t_list_head blocks;
	t_usize		size;
	t_wall		*map;
	t_vec2d		spawn;
}				t_map;

typedef struct	s_map_args
{
	const char	*path;
}				t_map_args;

t_constructor	map(const char *const path);

t_result		init_map(t_map *self, const t_map_args *const args);

t_result		map_parse_texture_list(t_map *const self,
					char *textures_flag_str);
t_result		map_parse_block_list(t_map *const self,
					char *blocks_flag_str);
t_result		map_parse_size(t_map *const self,
					char *size_flag_str);
t_result		map_parse_map(t_map *const self,
					char *map_flag_str);
t_result		map_parse_player(t_map *const self,
					char *player_flag_str);

void			destroy_map(t_map *const self);

#endif
