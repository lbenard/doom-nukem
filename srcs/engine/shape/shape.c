/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:55:08 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/05 23:55:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/shape.h"

t_constructor	shape(void)
{
	return (ft_constructor(
		init_shape,
		destroy_shape,
		sizeof(t_shape),
		NULL));
}