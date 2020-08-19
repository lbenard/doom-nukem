/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widepunchman_entity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:47:17 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 04:11:16 by mribouch         ###   ########.fr       */
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
