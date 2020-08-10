/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:40:39 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/06 18:40:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/pistol_entity.h"

void	destroy_pistol_entity(t_pistol_entity *const self)
{
	destroy_weapon_entity(&self->super);
}
