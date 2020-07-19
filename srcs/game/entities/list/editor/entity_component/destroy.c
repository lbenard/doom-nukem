/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:38:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 21:25:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_component_entity.h"

void	destroy_entity_component_entity(t_entity_component_entity *const self)
{
	destroy_module(&self->super.super.module);
}
