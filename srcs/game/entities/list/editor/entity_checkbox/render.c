/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 00:52:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 21:00:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_checkbox_entity.h"

void	entity_checkbox_entity_render(t_entity_checkbox_entity *const self,
			t_frame *const frame)
{
	checkbox_entity_render(&self->super, frame);
}
