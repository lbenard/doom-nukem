/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:29 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:26:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/classic_entity.h"

t_result	init_classic_entity(t_classic_entity *const self,
				const t_transform transform,
				void (*update_fn)())
{
	init_module(&self->module);
	self->transform = transform;
	self->update_fn = update_fn;
	return (OK);
}
