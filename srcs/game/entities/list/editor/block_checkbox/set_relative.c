/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_relative.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 01:15:23 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 01:16:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_checkbox_entity.h"

void	block_checkbox_set_relative(t_block_checkbox_entity *const self,
			const t_checkbox_position position)
{
	checkbox_set_relative(&self->super.super, position);
}
