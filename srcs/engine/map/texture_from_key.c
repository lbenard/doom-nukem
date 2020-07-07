/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_from_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:06:43 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/06 23:53:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"
#include "ft/str.h"

t_texture_node	*texture_from_key(t_list_head *const self,
					const char *const key)
{
	t_list_head		*pos;
	t_texture_node	*texture;

	pos = self;
	while ((pos = pos->next) != self)
	{
		texture = (t_texture_node*)((t_u8*)pos
			- __builtin_offsetof(t_texture_node, node));
		if (!ft_strcmp(texture->key, key))
			return (texture);
	}
	return (NULL);
}
