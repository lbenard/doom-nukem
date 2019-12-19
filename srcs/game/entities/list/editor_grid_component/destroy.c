/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:19:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/18 22:19:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_grid_component_entity.h"

void	destroy_editor_grid_component_entity(
			t_editor_grid_component_entity *const self)
{
	destroy_module(&self->super.super.module);
}