/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hmodule.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:53:05 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:53:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"
#include "engine/error.h"

void	free_hmodule(t_hmodule *const module)
{
	module->descriptor.free_fn(*module->module_ref);
	free(module);
}
