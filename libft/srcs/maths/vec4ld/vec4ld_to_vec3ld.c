/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4ld_to_vec3ld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:30:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:27:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec4ld.h"

t_vec3ld	vec4ld_to_vec3ld(t_vec4ld src)
{
	t_vec3ld	dst;

	dst.x = src.x;
	dst.y = src.y;
	dst.z = src.z;
	return (dst);
}
