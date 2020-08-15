/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 01:16:07 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 01:16:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_checkbox_entity.h"

void	block_checkbox_set_pos(t_block_checkbox_entity *const self,
			const t_vec3f pos)
{
	checkbox_set_pos(&self->super.super, pos);
}
