/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtable.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:29:28 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:25:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity.h"

struct s_entity_vtable	entity_vtable(void (*update)(struct s_entity *const))
{
	struct s_entity_vtable	vtable;

	vtable.update = update;
	return (vtable);
}
