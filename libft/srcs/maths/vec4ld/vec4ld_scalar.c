/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4ld_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:30:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:27:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec4ld.h"

t_vec4ld	vec4ld_scalar(t_vec4ld src, long double a)
{
	src.x *= a;
	src.y *= a;
	src.z *= a;
	src.w *= a;
	return (src);
}
