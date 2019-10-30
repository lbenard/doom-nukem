/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:55:14 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 13:01:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/raycasting_scene.h"

void	free_raycasting_scene(t_raycasting_scene *const self)
{
	destroy_scene(&self->super);
	free(self);
}
