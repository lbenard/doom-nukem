/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:02:28 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/29 15:03:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/vector.h"

t_smodule_factory	vector(void)
{
	return (ft_smodule_factory(
		ft_smodule_descriptor(init_ve)))
}