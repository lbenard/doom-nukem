/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 03:17:23 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/04 03:20:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/weapon_entity.h"

void	destroy_weapon_entity(t_weapon_entity *const self)
{
	destroy_sprite_entity(&self->super);
}