/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widepunchman_entity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:47:17 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 04:24:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/widepunchman_entity.h"

t_constructor	widepunchman_entity(t_scene *const scene, const t_vec2f pos)
{
	static t_widepunchman_entity_args	args;

	args.scene = scene;
	args.pos = pos;
	return (ft_constructor(init_widepunchman_entity,
		destroy_widepunchman_entity,
		sizeof(t_widepunchman_entity),
		&args));
}
