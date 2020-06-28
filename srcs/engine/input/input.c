/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:17:36 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:24:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

t_constructor	input(void)
{
	return (ft_constructor(init_input, destroy_input, sizeof(t_input), NULL));
}
