/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 05:13:20 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/05 01:59:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/sprite.h"
#include "engine/error.h"

t_result	init_sprite(t_sprite *const self)
{
	init_module(&self->module);
	if (!(self->sprite = sfSprite_create()))
		return (throw_result_str("init_sprite()", "failed to create sprite"));
	return (OK);
}
