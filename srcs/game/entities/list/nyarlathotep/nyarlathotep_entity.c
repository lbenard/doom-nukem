/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nyarlathotep_entity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 01:08:03 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/07 01:20:56 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/nyarlathotep_entity.h"

t_constructor	nyarlathotep_entity(t_scene *const scene, const t_vec2f pos)
{
	static t_nyarlathotep_entity_args args;

	args.scene = scene;
	args.pos = pos;
	return (ft_constructor(init_nyarlathotep_entity,
		destroy_nyarlathotep_entity, sizeof(t_nyarlathotep_entity), &args));
}