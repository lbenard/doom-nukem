/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_static.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:32:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/07 17:04:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/string.h"
#include "ft/str.h"

t_result	init_static_string(t_static_string *const self,
				const t_static_string_args *const args)
{
	self->str = args->str;
	self->len = ft_strlen(self->str);
	return (OK);
}