/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 23:07:41 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/08 15:29:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/vertex_component_entity.h"

void	destroy_vertex_component_entity(t_vertex_component_entity *const self)
{
	destroy_module(&self->super.super.module);
}