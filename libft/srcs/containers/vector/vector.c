/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:33:00 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:51:58 by mribouch         ###   ########.fr       */
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
