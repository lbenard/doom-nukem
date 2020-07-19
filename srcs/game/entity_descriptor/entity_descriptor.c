/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_descriptor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:13:16 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 17:28:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entity_descriptor.h"

t_constructor	entity_descriptor(const char *const name,
					const char *const icon_path,
					const t_constructor_fn constructor_fn)
{
	static t_entity_descriptor_args	args;

	args.name = name;
	args.icon_path = icon_path;
	args.constructor_fn = constructor_fn;
	return (ft_constructor(init_entity_descriptor,
		destroy_entity_descriptor,
		sizeof(t_entity_descriptor),
		&args));
}
