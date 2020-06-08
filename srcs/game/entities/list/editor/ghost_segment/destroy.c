/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:33:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/14 06:31:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/ghost_segment_component_entity.h"

void	destroy_ghost_segment_component_entity(
			t_ghost_segment_component_entity *const self)
{
	destroy_module(&self->super.super.module);
}