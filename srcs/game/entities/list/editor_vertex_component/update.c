/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:48:38 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/21 17:08:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_vertex_component_entity.h"

#include <stdio.h>

void	editor_vertex_component_entity_update(
			t_editor_vertex_component_entity *const self)
{
	printf("vertex pos: %f %f\n", self->super.super.transform.position.x,
		self->super.super.transform.position.y);
	(void)self;
}