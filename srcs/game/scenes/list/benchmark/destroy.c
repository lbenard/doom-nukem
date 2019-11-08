/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:30:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:36:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/benchmark_scene.h"

void	destroy_benchmark_scene(t_benchmark_scene *const self)
{
	destroy_module(&self->super.module);
}