/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 09:51:29 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/03 09:53:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/blend.h"

t_rgba	blend_colorize(const t_rgba back, const t_rgba front)
{
	t_rgba	result;

	result = front;
	result.c.a = back.c.a;
	return (result);
}