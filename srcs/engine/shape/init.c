/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:17:07 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/05 23:18:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/shape.h"

t_result	init_shape(t_shape *const self)
{
	init_module(&self->module);
	init_list_head(&self->vertices);
	return (OK);
}