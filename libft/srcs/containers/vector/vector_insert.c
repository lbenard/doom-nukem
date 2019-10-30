/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:37:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 21:16:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/vector.h"
#include "ft/mem.h"

t_result	vector_insert(t_vector *vector, size_t pos, const void *data,
	size_t size)
{
	size_t	new_capacity;

	if (!data || pos > vector->size)
		return (ERROR);
	if (vector->capacity == 0)
	{
		vector_push_back(vector, data, size);
		return (OK);
	}
	new_capacity = vector->capacity;
	while (new_capacity < vector->size + size)
		new_capacity *= 2;
	vector_reserve(vector, new_capacity);
	ft_memmove((t_u8*)vector->data + pos + size, (t_u8*)vector->data + pos,
		vector->size - pos);
	ft_memcpy((t_u8*)vector->data + pos, data, size);
	vector->size += size;
	return (OK);
}
