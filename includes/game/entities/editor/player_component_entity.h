/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_component_entity.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:32:22 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/05 00:57:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_COMPONENT_ENTITY_H
# define PLAYER_COMPONENT_ENTITY_H

# include "game/entities/editor/component_entity.h"

typedef struct	s_player_component_entity
{
	t_component_entity	super;
	t_frame				spawn_icon;
}				t_player_component_entity;

typedef struct	s_player_component_entity_args
{
	const char	*icon_path;
}				t_player_component_entity_args;

t_constructor	player_component_entity(const char *const icon_path);

t_result		init_player_component_entity(
					t_player_component_entity *const self,
					t_player_component_entity_args *const args);

void			player_component_entity_update(
					t_player_component_entity *const self);
void			player_component_entity_render(
					t_component_entity *const self,
					t_editor_camera_entity *const camera,
					t_frame *const fb);
t_bool			player_component_entity_is_hovered(
					t_component_entity *const self,
					t_editor_camera_entity *const camera,
					const t_frame *const frame,
					const t_isize mouse_pos);

void			destroy_player_component_entity(
					t_player_component_entity *const self);

#endif
