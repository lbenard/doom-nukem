/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:12:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 17:30:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entity_descriptor.h"

void	destroy_entity_descriptor(t_entity_descriptor *const self)
{
	destroy_module(&self->module);
}
