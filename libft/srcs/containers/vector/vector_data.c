/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:34:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 20:35:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/vector.h"

t_constructor	vector_data(const void *data, const size_t size)
{
	static t_vector_args	args;

	args.data = data;
	args.size = size;
	return (ft_constructor(init_vector,
		destroy_vector,
		sizeof(t_vector),
		&args));
}