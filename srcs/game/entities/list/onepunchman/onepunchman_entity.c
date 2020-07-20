/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onepunchman_entity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:47:17 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/20 18:54:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/onepunchman_entity.h"

t_constructor	onepunchman_entity(t_scene *const scene, const t_vec2f pos)
{
	static t_onepunchman_entity_args	args;

	args.scene = scene;
	args.pos = pos;
	return (ft_constructor(init_onepunchman_entity,
		destroy_onepunchman_entity,
		sizeof(t_onepunchman_entity),
		&args));
}