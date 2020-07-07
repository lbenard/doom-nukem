/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:47:08 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/05 00:47:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/player_component_entity.h"

void	destroy_player_component_entity(t_player_component_entity *const self)
{
	destroy_module(&self->super.super.module);
}
