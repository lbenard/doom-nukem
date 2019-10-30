/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:27:20 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/29 14:59:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

t_result	init_input(t_input *const self)
{
	init_module(&self->module);
	module_add_smodule(&self->module, event_handler(self), &self->handler);
	init_vector(&self->table);
	init_vector(&self->events);
}
