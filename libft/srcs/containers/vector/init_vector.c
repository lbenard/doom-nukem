/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:57:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 20:30:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/vector.h"

t_result	init_vector(t_vector *const vector)
{
	vector->capacity = 0;
	vector->size = 0;
	vector->data = NULL;
	return (OK);
}
