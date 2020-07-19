/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 00:51:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 21:01:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_checkbox_entity.h"

void	entity_checkbox_entity_update(t_entity_checkbox_entity *const self)
{
	checkbox_entity_update(&self->super);
}
