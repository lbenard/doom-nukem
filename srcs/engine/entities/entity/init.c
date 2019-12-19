/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:29 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 21:28:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity.h"

t_result	init_entity(t_entity *const self,
				const t_transform transform,
				const struct s_entity_vtable vtable)
{
	init_module(&self->module);
	self->transform = transform;
	self->vtable = vtable;
	return (OK);
}
