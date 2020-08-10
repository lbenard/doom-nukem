/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_addition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:38:50 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/10 15:24:19 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/vec3f.h"

t_vec3f	vec3f_addition(t_vec3f a, t_vec3f b)
{
	t_vec3f	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;

	return (ret);
}
