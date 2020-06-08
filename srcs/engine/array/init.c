/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:12:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/05 01:58:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/array.h"
#include "engine/error.h"

t_result	init_array(t_array *const self, const t_array_args *const args)
{
	init_module(&self->module);
	if (!(self->array = (void*)malloc(args->size)))
		return (throw_result_str("init_array()", "failed to allocate array"));
	self->size = args->size;
	return (OK);
}