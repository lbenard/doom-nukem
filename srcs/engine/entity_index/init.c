/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:51:09 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:26:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_index.h"

t_result	init_entity_index(t_entity_index *const self)
{
	init_module(&self->module);
	init_list_head(&self->descriptors);
	return (OK);
}
