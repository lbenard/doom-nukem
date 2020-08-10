/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:48:35 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/10 17:49:06 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/fireball_entity.h"

void			destroy_fireball_entity(t_fireball_entity *const self)
{
	destroy_sprite_entity(&self->super);
}
