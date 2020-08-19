/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_entity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 21:56:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 17:49:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/component_entity.h"

t_constructor	component_entity(const struct s_component_entity_vtable vtable)
{
	static t_component_entity_args	args;

	args.vtable = vtable;
	return (ft_constructor(init_component_entity,
		destroy_component_entity,
		sizeof(t_component_entity),
		&args));
}
