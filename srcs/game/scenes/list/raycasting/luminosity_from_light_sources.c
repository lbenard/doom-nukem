/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luminosity_from_light_sources.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 10:42:25 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 12:00:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/maths.h"
#include "game/scenes/raycasting_scene.h"

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
		if (vec3f_squared_distance(light_source->transform.position, pos)
			< 25.0f)
		{
			distance = vec3f_distance(light_source->transform.position, pos);
			if (distance < 5.0f)
				light = ft_fmin(light + (5.0f - distance) / 5.0f, 1.0f);
		}
	}
	return (light);
}
