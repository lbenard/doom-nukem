/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:56:05 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/18 19:56:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_component_entity.h"

void	destroy_editor_component_entity(t_editor_component_entity *const self)
{
	destroy_module(&self->super.module);
}