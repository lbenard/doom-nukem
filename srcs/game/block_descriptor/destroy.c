/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:12:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 17:26:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/block_descriptor.h"

void	destroy_block_descriptor(t_block_descriptor *const self)
{
	destroy_module(&self->module);
}
