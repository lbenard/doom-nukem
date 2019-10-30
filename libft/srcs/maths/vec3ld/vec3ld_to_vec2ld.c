/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3ld_to_vec2ld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:28:05 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:26:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec3ld.h"

t_vec2ld	vec3ld_to_vec2ld(t_vec3ld src)
{
	t_vec2ld	dst;

	dst.x = src.x;
	dst.y = src.y;
	return (dst);
}
