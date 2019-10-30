/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_smodule.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:53:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:53:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/module.h"
#include "engine/error.h"

void	free_smodule(t_smodule *const module)
{
	module->descriptor.destroy_fn(module->module_ref);
	free(module);
}
