/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:41:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 21:43:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/vector.h"

t_result	vector_double(t_vector *vector)
{
	return (vector_reserve(vector, vector->capacity * 2));
}