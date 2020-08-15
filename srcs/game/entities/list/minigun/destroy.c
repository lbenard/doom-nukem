/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:40:39 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 19:23:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/minigun_entity.h"

void	destroy_minigun_entity(t_minigun_entity *const self)
{
	destroy_weapon_entity(&self->super);
}
