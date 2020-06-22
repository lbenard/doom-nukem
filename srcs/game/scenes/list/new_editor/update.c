/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:25:39 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/22 02:54:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/new_editor_scene.h"
#include "engine/delta.h"

#include <stdio.h>

void	new_editor_scene_update(t_new_editor_scene *const self)
{
	entity_list_update(&self->super.entities);
	printf("blocks: %lu\n", list_size(&self->blocks));
	printf("entities: %lu\n", list_size(&self->entities));
}