/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:19:26 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/23 19:41:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/grid_component_entity.h"

void	destroy_grid_component_entity(t_grid_component_entity *const self)
{
	destroy_module(&self->super.module);
}