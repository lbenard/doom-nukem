/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smodule_descriptor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:53:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:56:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

t_smodule_descriptor	ft_smodule_descriptor(enum e_result (*init_fn)(),
							void (*destroy_fn)())
{
	t_smodule_descriptor	descriptor;

	descriptor.init_fn = init_fn;
	descriptor.destroy_fn = destroy_fn;
	return (descriptor);
}
