/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 00:10:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 05:16:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/string.h"
#include "engine/error.h"
#include "ft/str.h"

t_result	init_string(t_string *const self, const t_string_args *const args)
{
	if (!(self->str = ft_strdup(args->str)))
		return (throw_result_str("init_string()", "failed to dup string"));
	return (OK);
}