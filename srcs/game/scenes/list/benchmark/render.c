/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:21:28 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 15:35:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "game/scenes/benchmark_scene.h"
#include "game/entities/button_entity.h"
#include "engine/delta.h"

#include <stdio.h>

t_frame		*g_frame;

static void	render_button(t_entity_node *const node)
{
	t_button_entity	*button;

	button = (t_button_entity*)node->entity;
	(void)button;
	// button->super.transform.position.x = (float)(rand() / (double)RAND_MAX * (g_frame->size.x - 1));
	// button->super.transform.position.y = (float)(rand() / (double)RAND_MAX * (g_frame->size.y - 1));
	// button_entity_render(button, g_frame);
}

void		benchmark_scene_render(t_benchmark_scene *const self,
				t_frame *const fb) 
{
	g_frame = fb;
	static size_t	total_frame = 0;
	static float	total_spf = 0.0f;

	total_spf += get_last_delta();
	// srand(time(NULL));
	printf("average fps: %f\n", 1.0f / (total_spf / total_frame++));
	list_foreach(&self->super.entities.list, 0, render_button);
}
