/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 00:52:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 00:53:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_checkbox_entity.h"

void	block_checkbox_entity_render(t_block_checkbox_entity *const self,
			t_frame *const frame)
{
	preview_checkbox_entity_render(&self->super, frame);
}
