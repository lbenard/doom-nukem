/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_shrink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:24:04 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 20:01:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/vector.h"
#include "ft/mem.h"

t_result	vector_shrink(t_vector *vector)
{
	void	*new_data;

	if (vector->capacity == vector->size)
		return (OK);
	if (!(new_data = malloc(vector->size)))
	{
		free(vector->data);
		init_vector(vector);
		return (ERROR);
	}
	ft_memcpy(new_data, vector->data, vector->size);
	vector->data = new_data;
	vector->capacity = vector->size;
	return (OK);
}
