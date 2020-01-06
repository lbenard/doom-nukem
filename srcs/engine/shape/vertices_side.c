/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertices_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:28:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/05 23:30:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/shape.h"

t_bool	vertices_side(t_isize p, t_isize a, t_isize b)
{
	return (0 < (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x));
}