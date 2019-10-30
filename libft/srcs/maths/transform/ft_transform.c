/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:22:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/23 21:23:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/transform.h"

t_transform	ft_transform(t_vec3f position, t_vec3f rotation, t_vec3f scale)
{
	t_transform	ret;

	ret.position = position;
	ret.rotation = rotation;
	ret.scale = scale;
	return (ret);
}
