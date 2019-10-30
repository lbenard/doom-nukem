/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_smodule.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:53:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:56:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"
#include "engine/error.h"

t_smodule	*new_smodule(void *const module, t_smodule_descriptor descriptor)
{
	t_smodule	*ret;

	if (!(ret = (t_smodule*)malloc(sizeof(t_smodule))))
	{
		return (throw_error_str("new_smodule()",
			"failed to allocate new stack module node"));
	}
	init_list_head(&ret->node);
	ret->module_ref = module;
	ret->descriptor = descriptor;
	return (ret);
}
