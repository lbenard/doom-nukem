/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constructor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 02:26:01 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 04:58:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/module.h"

t_constructor	ft_constructor(enum e_result (*const constructor_fn)(),
					void (*const destructor_fn)(),
					const size_t module_size,
					const void *const args)
{
	t_constructor	constructor;

	constructor.constructor_fn = constructor_fn;
	constructor.destructor_fn = destructor_fn;
	constructor.module_size = module_size;
	constructor.args = args;
	return (constructor);
}
