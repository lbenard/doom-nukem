/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:22:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/23 21:25:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/transform.h"

t_transform	ft_transform_default(void)
{
	t_transform ret;

	ret.position = ft_vec3f(0.0f, 0.0f, 0.0f);
	ret.rotation = ft_vec3f(0.0f, 0.0f, 0.0f);
	ret.scale = ft_vec3f(1.0f, 1.0f, 1.0f);
	return (ret);
}
