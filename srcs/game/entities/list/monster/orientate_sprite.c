/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientate_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:35:48 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/10 17:36:36 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"

static float	diamond_angle(float x, float y)
{
	if (y >= 0)
		return (x >= 0 ? y / (x + y) : 1 - x / (-x + y));
	else
		return (x < 0 ? 2 - y / (-x - y) : 3 + x / (x - y));
}

static float	angle_gap(float p, float m)
{
	float diff;

	diff = p - m;
	if (diff < 0)
		return (diff + 4);
	return (diff);
}

static float	compute_angle_to_player(t_monster_entity *self)
{
	t_vec3f	player_pos;
	t_vec3f	monster_pos;
	t_vec3f	dir_to_player;
	float	monster_angle;
	float	player_angle;

	player_pos = self->player_ref->super.transform.position;
	monster_pos = self->super.super.transform.position;
	dir_to_player = ft_vec3f(player_pos.x - monster_pos.x,
						player_pos.y - monster_pos.y, 0);
	monster_angle = diamond_angle(self->super.super.transform.direction.x,
		self->super.super.transform.direction.y);
	player_angle = diamond_angle(dir_to_player.x, dir_to_player.y);
	return (angle_gap(player_angle, monster_angle));
}

static int		face4(float a)
{
	if (a >= 3.5 || a <= 0.5)
		return (0);
	if (0.5 <= a && a <= 1.5)
		return (3);
	if (1.5 <= a && a <= 2.5)
		return (2);
	return (1);
}

int				get_orientate_sprite(t_monster_entity *self)
{
	float	angle;
	int		index;

	angle = compute_angle_to_player(self);
	index = face4(angle);
	return (index);
}
