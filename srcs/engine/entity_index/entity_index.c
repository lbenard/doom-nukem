/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:50:05 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/04 18:51:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity_index.h"

t_constructor	entity_index(void)
{
	return (ft_constructor(init_entity_index,
		destroy_entity_index,
		sizeof(t_entity_index),
		NULL));
}