/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:20:20 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 18:46:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/benchmark_scene.h"

void	benchmark_scene_update(t_benchmark_scene *const self)
{
	(void)self;
	entity_list_update(&self->super.entities);
}
