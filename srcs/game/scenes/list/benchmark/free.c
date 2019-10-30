/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:30:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 13:35:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/benchmark_scene.h"

void	free_benchmark_scene(t_benchmark_scene *const self)
{
	destroy_module(&self->super.module);
	free(self);
}