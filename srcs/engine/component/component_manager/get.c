/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:18:20 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:19:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/component.h"

void	*component_manager_get(t_component_manager *const self,
			const t_entity_uid entity_id)
{
	return (self->list.data + (self->component_size) * entity_id);
}