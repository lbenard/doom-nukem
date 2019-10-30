/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:14:53 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/26 22:15:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/array.h"

t_smodule_factory	array(size_t size)
{
	static t_array_args	args;

	args.size = size;
	return (ft_smodule_factory(
		ft_smodule_descriptor(init_array, destroy_array),
		&args));
}