/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_checkbox_entity.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 00:31:34 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 20:56:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_checkbox_entity.h"

t_constructor	entity_checkbox_entity(const char *const base_name,
					const t_entity_descriptor *const entity,
					const t_window *const window)
{
	static t_entity_checkbox_entity_args	args;

	args.base_name = base_name;
	args.entity = entity;
	args.window = window;
	return (ft_constructor(init_entity_checkbox_entity,
		destroy_entity_checkbox_entity,
		sizeof(t_entity_checkbox_entity),
		&args));
}
