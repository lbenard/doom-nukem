/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smodule_factory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:53:50 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:56:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/module.h"

t_smodule_factory	ft_smodule_factory(const t_smodule_descriptor descriptor,
						const void *args)
{
	t_smodule_factory	factory;

	factory.descriptor = descriptor;
	factory.args = args;
	return (factory);
}
