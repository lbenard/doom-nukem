/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:54:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_list.h"

t_smodule_factory	entity_list(void)
{
	return (ft_smodule_factory(ft_smodule_descriptor(
		init_entity_list, destroy_entity_list), NULL));
}
