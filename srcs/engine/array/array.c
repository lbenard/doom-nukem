/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 22:14:53 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:40:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/array.h"

t_constructor	array(size_t size)
{
	static t_array_args	args;

	args.size = size;
	return (ft_constructor(init_array, destroy_array, sizeof(t_array), &args));
}
