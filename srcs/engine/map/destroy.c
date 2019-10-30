/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:51:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 23:53:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"

void	destroy_map(t_map *self)
{
	destroy_module(&self->module);
	free_texture_list(&self->textures);
	free_block_list(&self->blocks);
	free(self->map);
}
