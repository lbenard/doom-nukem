/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:13:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:33:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/minimap_entity.h"

void	destroy_minimap_entity(t_minimap_entity *const self)
{
	destroy_module(&self->super.module);
}
