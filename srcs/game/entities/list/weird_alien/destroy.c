/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:01:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/27 18:17:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/weird_alien_entity.h"

void	destroy_weird_alien_entity(t_weird_alien_entity *const self)
{
	destroy_module(&self->super.super.super.module);
}
