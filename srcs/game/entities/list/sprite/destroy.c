/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 23:42:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/04 02:29:46 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/sprite_entity.h"
#include "game/scenes/raycasting_scene.h"

void	destroy_sprite_entity(t_sprite_entity *const self)
{
	t_raycasting_scene	*scene;

	scene = (t_raycasting_scene*)game_singleton()->scene;
	destroy_module(&self->super.module);
	entity_list_remove(&scene->sprite_entities, &self->super);
}
