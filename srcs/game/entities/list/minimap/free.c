/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:13:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 15:52:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/minimap_entity.h"

void	free_minimap_entity(t_minimap_entity *const self)
{
	destroy_module(&self->super.module);
	free(self);
}
