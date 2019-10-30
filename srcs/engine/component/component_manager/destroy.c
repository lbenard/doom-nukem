/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:07:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:08:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/component.h"

void	destroy_component_manager(t_component_manager *const self)
{
	destroy_module(&self->module);
	destroy_vector(&self->list);
	free(self->name);
}