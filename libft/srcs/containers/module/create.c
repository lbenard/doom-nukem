/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 05:26:28 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:49:17 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/module.h"

t_result	static_module_create(void *const module,
				const t_constructor constructor)
{
	if (constructor.args)
		return (constructor.constructor_fn(module, constructor.args));
	else
		return (constructor.constructor_fn(module));
}
