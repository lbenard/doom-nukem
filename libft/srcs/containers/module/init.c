/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 03:02:17 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/05 01:55:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/module.h"

t_result	init_module(t_module *const self)
{
	init_list_head(&self->modules);
	init_list_head(&self->node);
	self->has_error = FALSE;
	return (OK);
}