/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 01:41:23 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/27 01:43:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/string.h"
#include "engine/error.h"
#include "ft/str.h"

t_result	string_set(t_string *const self, const char *const str)
{
	free((char*)self->str);
	if (!(self->str = ft_strdup(str)))
	{
		return (throw_result_str("string_set()",
			"failed to allocate new string"));
	}
	return (OK);
}