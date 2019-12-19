/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:20:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 21:29:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/entity.h"

t_result	init_entity_default(t_entity *const self,
				const struct s_entity_vtable vtable)
{
	init_entity(self, ft_transform_default(), vtable);
	return (OK);
}
