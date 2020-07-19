/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descriptor_from_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 01:40:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 01:42:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entity_descriptor.h"
#include "ft/str.h"

t_entity_descriptor	*descriptor_from_name(
						t_entity_descriptor *const descriptors,
						const size_t amount,
						const char *const name)
{
	size_t	i;

	i = 0;
	while (i < amount)
	{
		if (ft_strcmp(descriptors[i].name, name) == 0)
			return (&descriptors[i]);
		i++;
	}
	return (NULL);
}
