/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmodule_descriptor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:53:16 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:56:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

t_hmodule_descriptor	ft_hmodule_descriptor(void *(*new_fn)(),
							void (*free_fn)())
{
	t_hmodule_descriptor	descriptor;

	descriptor.new_fn = new_fn;
	descriptor.free_fn = free_fn;
	return (descriptor);
}
