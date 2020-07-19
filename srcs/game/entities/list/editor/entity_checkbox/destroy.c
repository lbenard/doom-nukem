/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 00:53:00 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 21:01:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/entity_checkbox_entity.h"

void	destroy_entity_checkbox_entity(t_entity_checkbox_entity *const self)
{
	destroy_checkbox_entity(&self->super);
}
