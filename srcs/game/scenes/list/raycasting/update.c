/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:41:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/20 19:58:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"

#include <stdio.h>

void	raycasting_scene_update(t_raycasting_scene *const self)
{
	t_list_head		*pos;
	t_sprite_entity	*sprite_node;
	t_vec2f			relative_pos;

	entity_list_update(&self->super.entities);
	// printf("player pos: %lf %lf\n",
	// 	self->player_ref->super.transform.position.x,
	// 	self->player_ref->super.transform.position.y);
	
	pos = &self->sprite_entities.list;
	while ((pos = pos->next) != &self->sprite_entities.list)
	{
		sprite_node = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		relative_pos.x = self->player_ref->super.transform.position.x - sprite_node->super.transform.position.x;
		relative_pos.y = self->player_ref->super.transform.position.y - sprite_node->super.transform.position.y;
		sprite_node->super.transform.position.x += relative_pos.x * 1.0f * get_last_delta();
		sprite_node->super.transform.position.y += relative_pos.y * 1.0f * get_last_delta();
		// printf("sprite pos: %lf %lf\n",
		// 	sprite_node->super.transform.position.x,
		// 	sprite_node->super.transform.position.y);
	}

	// self->renderer.pos =
	// 	vec3f_to_vec2f(self->player_ref->super.transform.position);
	// self->renderer.dir.x = cos(self->player_ref->super.transform.rotation.y);
	// self->renderer.dir.y = sin(self->player_ref->super.transform.rotation.y);
	// self->renderer.plane.x = -sin(self->player_ref->super.transform.rotation.y);
	// self->renderer.plane.y = cos(self->player_ref->super.transform.rotation.y);
	// if (self->player_ref->super.transform.rotation.y < M_PI)
	// 	self->player_ref->super.transform.rotation.y += 2.0f * M_PI;
	// if (self->player_ref->super.transform.rotation.y > M_PI)
	// 	self->player_ref->super.transform.rotation.y -= 2.0f * M_PI;
	// self->renderer.plane = ft_vec2f(
	// 	planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed),
	// 	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed));
}
