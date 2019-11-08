/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:33:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 20:34:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/vector.h"

t_constructor	vector(void)
{
	return (ft_constructor(init_vector,
		destroy_vector,
		sizeof(t_vector),
		NULL));
}