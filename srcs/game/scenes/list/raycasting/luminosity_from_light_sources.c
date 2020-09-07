/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luminosity_from_light_sources.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 10:42:25 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 13:31:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "maths/maths.h"
#include "game/scenes/raycasting_scene.h"

float	sqrt_distance(t_vec3f a, t_vec3f b)
{
	return (sqrt(
		(a.x - b.x) * (a.x - b.x)
		+ (a.y - b.y) * (a.y - b.y)
		+ (a.z - b.z) * (a.z - b.z)));
}

float	squared_distance(t_vec3f a, t_vec3f b)
{
	return ((a.x - b.x) * (a.x - b.x)
		+ (a.y - b.y) * (a.y - b.y)
		+ (a.z - b.z) * (a.z - b.z));
}

float	raycasting_scene_luminosity_from_light_sources(
			const t_raycasting_scene *const self,
			const t_vec3f pos)
{
	const t_list_head	*list;
	const t_entity		*light_source;
	float				distance;
	float				light;

	list = &self->light_entities.list;
	light = 0.0f;
	while ((list = list->next) != &self->light_entities.list)
	{
		light_source = ((t_entity_node*)list)->entity;
		distance = squared_distance(light_source->transform.position, pos);
		if (distance < 25.0f)
		{
			light += (5.0f - distance / 5.0f) / 5.0f;
			if (light > 1.0f)
				light = 1.0f;
		}
	}
	return (light);
}
