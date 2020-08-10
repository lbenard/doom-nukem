/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:52:24 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/10 16:16:21 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/nyarlathotep_entity.h"
#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"

static t_vec3f	dir_according_na(int na)
{
	t_vec3f	ret;

	ret = ft_vec3f(0, 0, 0);
	if (na == 0)
		ret = ft_vec3f(1, 0, 0);
	else if (na == 1)
		ret = ft_vec3f(1, 1, 0);
	else if (na == 2)
		ret = ft_vec3f(0, 1, 0);
	else if (na == 3)
		ret = ft_vec3f(0, -1, 0);
	else if (na == 4)
		ret = ft_vec3f(-1, 0, 0);
	else if (na == 5)
		ret = ft_vec3f(-1, 1, 0);
	else if (na == 6)
		ret = ft_vec3f(-1, -1, 0);
	return (ret);
}

static t_vec3f	get_dir_move(t_nyarlathotep_entity *self, t_map map)
{
	t_vec3f	verif;
	t_vec3f	ret;
	t_vec3f	position;
	int		na;

	position = self->super.super.super.transform.position;
	na = (int)((get_wall_time() - (int)get_wall_time()) * 1000) % 7;
	ret = ft_vec3f(0, 0, 0);
	ret = dir_according_na(na);
	verif = vec3f_normalize(ret);
	verif = vec3f_scalar(ret, get_last_delta() * 2);
	if (map.map[(int)(position.x + verif.x * 6) +
		((int)(position.y + verif.y * 6) * map.size.x)].id == ' ')
		ret = vec3f_scalar(ret, -1.0f);
	return (ret);
}

void			rotate_nyarlathotep(t_nyarlathotep_entity *self,
					t_raycasting_scene *scene, t_vec3f velocity)
{
	if (self->angle >= 360)
	{
		self->end_circle = TRUE;
		self->end_move = FALSE;
		self->angle = 0;
	}
	if (self->is_moving == FALSE)
		self->super.super.super.transform.direction = velocity;
	self->super.animation.speed = 0.0f;
	self->angle += 1;
	if (self->end_circle == TRUE && self->end_move == FALSE &&
		self->is_moving == FALSE)
	{
		self->last_pos = self->super.super.super.transform.position;
		self->dir_move = get_dir_move(self, scene->map);
		self->is_moving = TRUE;
	}
}
