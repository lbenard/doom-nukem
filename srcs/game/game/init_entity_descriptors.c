/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_entity_descriptors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:21:42 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:01:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"
#include "game/entities/onepunchman_entity.h"

void	init_entity_descriptors(t_game *const self)
{
	module_add(&self->module, &self->entities_list.onepunchman,
		entity_descriptor("one_punch_man",
			"resources/sprites/onepunchman-icon.bmp",
			onepunchman_entity));
}