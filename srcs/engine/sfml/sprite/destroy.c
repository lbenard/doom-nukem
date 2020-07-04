/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 05:14:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/04 17:09:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/sprite.h"

void	destroy_sprite(t_sprite *const self)
{
	destroy_module(&self->module);
	sfSprite_destroy(self->sprite);
}
