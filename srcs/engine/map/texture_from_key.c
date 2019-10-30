/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_from_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:06:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 18:13:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"
#include "ft/str.h"

t_texture_node	*texture_from_key(t_list_head *const self,
					const char *const key)
{
	t_list_head	*pos;
	t_list_head	*next;

	pos = self;
	next = pos->next;
	while ((pos = next) != self)
	{
		next = next->next;
		if (!ft_strcmp((((t_texture_node*)pos)->key), key))
			return ((t_texture_node*)pos);
	}
	return (NULL);
}
