/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghast_entity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:47:17 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/07 01:06:44 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/ghast_entity.h"

t_constructor	ghast_entity(t_scene *const scene, const t_vec2f pos)
{
	static t_ghast_entity_args	args;

	args.scene = scene;
	args.pos = pos;
	return (ft_constructor(init_ghast_entity,
		destroy_ghast_entity,
		sizeof(t_ghast_entity),
		&args));
}