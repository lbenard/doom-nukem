/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vtable.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 21:32:13 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/19 21:32:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/sprite_entity.h"

t_sprite_entity_vtable	sprite_entity_vtable(
							void (*sprite_entity_update_fn)(t_sprite_entity*))
{
	t_sprite_entity_vtable	vtable;

	vtable.sprite_entity_update_fn = sprite_entity_update_fn;
	return (vtable);
}