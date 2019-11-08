/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:54:46 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:51:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_list.h"

t_constructor	entity_list(void)
{
	return (ft_constructor(init_entity_list,
		destroy_entity_list,
		sizeof(t_entity_list),
		NULL));
}
