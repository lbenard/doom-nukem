/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:41:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 15:56:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/player_entity.h"

void	free_player_entity(t_player_entity *const self)
{
	destroy_module(&self->super.module);
	free(self);
}
