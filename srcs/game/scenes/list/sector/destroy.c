/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:25:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/05/23 18:17:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/sector_scene.h"

void	destroy_sector_scene(t_sector_scene *const self)
{
	free(self->sectors);
	destroy_module(&self->super.module);
}