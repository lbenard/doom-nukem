/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:44:58 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 00:24:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "game/entities/medikit_entity.h"

void	destroy_medikit_entity(t_medikit_entity *const self)
{
	destroy_sprite_entity(&self->super);
}
