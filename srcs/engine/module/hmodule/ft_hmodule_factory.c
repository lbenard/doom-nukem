/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hmodule_factory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:53:23 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:56:26 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

t_hmodule_factory	ft_hmodule_factory(const t_hmodule_descriptor descriptor,
							const void *args)
{
	t_hmodule_factory	factory;

	factory.descriptor = descriptor;
	factory.args = args;
	return (factory);
}
