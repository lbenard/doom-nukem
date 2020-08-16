/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:40:39 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 02:44:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/shotgun_entity.h"

void	destroy_shotgun_entity(t_shotgun_entity *const self)
{
	destroy_weapon_entity(&self->super);
}
