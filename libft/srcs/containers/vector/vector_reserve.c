/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reserve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 21:08:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:31:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/vector.h"
#include "ft/mem.h"

t_result	vector_reserve(t_vector *vector, size_t capacity)
{
	void	*new_data;

	if (vector->capacity >= capacity)
		return (OK);
	if (!(new_data = malloc(capacity)))
	{
		free(vector->data);
		init_vector(vector);
		return (ERROR);
	}
	ft_memcpy(new_data, vector->data, vector->size);
	free(vector->data);
	vector->data = new_data;
	vector->capacity = capacity;
	return (OK);
}
