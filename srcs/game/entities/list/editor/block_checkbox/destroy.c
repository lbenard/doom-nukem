/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 00:53:00 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 00:53:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_checkbox_entity.h"

void	destroy_block_checkbox_entity(t_block_checkbox_entity *const self)
{
	destroy_preview_checkbox_entity(&self->super);
}
