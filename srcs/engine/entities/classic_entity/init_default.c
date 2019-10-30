/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:26:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/classic_entity.h"

t_result	init_classic_entity_default(t_classic_entity *const self,
				void (*update_fn)())
{
	init_classic_entity(self, ft_transform_default(), update_fn);
	return (OK);
}
