/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vector_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:05:00 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/05 02:00:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/vector.h"
#include "ft/mem.h"

t_result	init_vector_data(t_vector *const vector,
				const t_vector_args *const args)
{
	init_module(&vector->module);
	if (!args->data)
		return (ERROR);
	if (!(vector->data = malloc(args->size)))
	{
		vector->capacity = 0;
		vector->size = 0;
		return (ERROR);
	}
	vector->capacity = args->size;
	vector->size = args->size;
	ft_memcpy(vector->data, args->data, args->size);
	return (OK);
}
