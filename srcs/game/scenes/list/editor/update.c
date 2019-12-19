/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:25:39 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 18:16:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "engine/delta.h"

void	editor_scene_update(t_editor_scene *const self)
{
	entity_list_update(&self->super.entities);
	// self->camera_ref->super.transform.scale.x += 1.0f * get_last_delta();
	// self->camera_ref->super.transform.position.x += 1.0f * get_last_delta();
	// self->camera_ref->super.transform.position.x = 0.0f;
	// self->camera_ref->super.transform.position.y = 0.0f;
}