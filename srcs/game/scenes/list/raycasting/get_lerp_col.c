/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lerp_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 22:00:51 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 04:17:33 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

static t_rgba	highest_value(t_rgba color1)
{
	float	highest_value;
	float	max_distance;
	t_rgba	ret;

	if (color1.c.r >= color1.c.g)
		highest_value = color1.c.r;
	else
		highest_value = color1.c.g;
	if (color1.c.b > highest_value)
		highest_value = color1.c.b;
	max_distance = (float)(highest_value / 255);
	ret = ft_rgba((color1.c.r / max_distance), (color1.c.g / max_distance),
		(color1.c.b / max_distance), 255);
	return (ret);
}

t_rgba			get_lerp_col(t_rgba color1, float dist, float value)
{
	t_rgba	c1;
	t_rgba	ret;
	int		color;

	c1 = color1;
	dist /= 2;
	ret.c.a = c1.c.a;
	value = value < 1.0f ? 1.0f : value;
	dist = dist <= 0.3f ? 0.3f : dist;
	color = c1.c.r / (dist * value);
	if (color >= 0 && color <= 255)
		ret.c.r = color;
	else
		return (highest_value(c1));
	color = c1.c.g / (dist * value);
	if (color >= 0 && color <= 255)
		ret.c.g = color;
	else
		return (highest_value(c1));
	color = c1.c.b / (dist * value);
	if (color >= 0 && color <= 255)
		ret.c.b = color;
	else
		return (highest_value(c1));
	return (ret);
}
