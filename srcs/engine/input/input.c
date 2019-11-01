/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:17:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/01 16:18:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

t_smodule_factory	input(void)
{
	return (ft_smodule_factory(
		ft_smodule_descriptor(init_input, destroy_input),
		NULL));
}