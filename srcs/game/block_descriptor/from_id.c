/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 21:28:10 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 21:29:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/block_descriptor.h"
#include "ft/str.h"

t_block_descriptor	*block_descriptor_from_id(
						t_block_descriptor *const descriptors,
						const size_t amount,
						const char id)
{
	size_t	i;

	i = 0;
	while (i < amount)
	{
		if (descriptors[i].id == id)
			return (&descriptors[i]);
		i++;
	}
	return (NULL);
}
