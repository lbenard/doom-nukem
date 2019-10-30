/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_hmodule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:53:29 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:56:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"
#include "engine/error.h"

t_hmodule	*new_hmodule(void **const module, t_hmodule_descriptor descriptor)
{
	t_hmodule	*ret;

	if (!(ret = (t_hmodule*)malloc(sizeof(t_hmodule))))
	{
		return (throw_error_str("new_hmodule()",
			"failed to allocate new heap module node"));
	}
	init_list_head(&ret->node);
	ret->module_ref = module;
	ret->descriptor = descriptor;
	return (ret);
}
