/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgba_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:42:11 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/21 15:36:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors/rgba.h"

t_rgba	ft_rgba_int(t_u32 color)
{
	t_rgba	result;

	result.integer = color;
	return (result);
}
