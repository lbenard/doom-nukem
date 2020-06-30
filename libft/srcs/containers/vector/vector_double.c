/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:41:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:51:48 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/vector.h"

t_result	vector_double(t_vector *const vector)
{
	return (vector_reserve(vector, vector->capacity * 2));
}
