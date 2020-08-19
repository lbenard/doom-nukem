/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:36:48 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 17:49:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/player_component_entity.h"
#include "engine/error.h"

t_result	init_player_component_entity(t_player_component_entity *const self,
				t_player_component_entity_args *const args)
{
	if (static_module_create(self, component_entity(
		(struct s_component_entity_vtable){
			player_component_entity_render,
			player_component_entity_is_hovered})) == ERROR)
	{
		return (throw_result_str("init_player_component_entity()",
			"failed to create parent class"));
	}
	module_add(&self->super.super.module, &self->spawn_icon,
		frame_from_file(args->icon_path));
	if (self->super.super.module.has_error)
	{
		destroy_player_component_entity(self);
		return (throw_result_str("init_player_component_entity()",
			"failed to init player component entity"));
	}
	return (OK);
}
