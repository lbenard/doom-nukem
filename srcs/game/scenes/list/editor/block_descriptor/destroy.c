/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:12:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 00:29:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_block_descriptor.h"

void	destroy_editor_block_descriptor(t_editor_block_descriptor *const self)
{
	destroy_module(&self->module);
}
