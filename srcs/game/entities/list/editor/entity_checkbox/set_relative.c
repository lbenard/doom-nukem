/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_relative.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 01:15:23 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 21:01:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_checkbox_entity.h"

void	entity_checkbox_set_relative(t_entity_checkbox_entity *const self,
			const t_checkbox_position position)
{
	checkbox_set_relative(&self->super, position);
}
