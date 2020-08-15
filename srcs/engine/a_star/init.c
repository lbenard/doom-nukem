/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:48:17 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 02:21:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/a_star.h"

static t_father	ft_initfather(void)
{
	t_father	ret;

	ret.pos.x = 0;
	ret.pos.y = 0;
	ret.f = 0;
	ret.g = 0;
	return (ret);
}

t_result		init_astar(t_star *a_star,
				const t_map *const map,
				t_entity monstre,
				t_entity player)
{
	if (!(a_star->closel = malloc(sizeof(t_star_list))))
		return (ERROR);
	if (!(a_star->openl = malloc(sizeof(t_star_list))))
		return (ERROR);
	a_star->start.pos.x = (int)monstre.transform.position.x;
	a_star->start.pos.y = (int)monstre.transform.position.y;
	a_star->end.pos.x = (int)player.transform.position.x;
	a_star->end.pos.y = (int)player.transform.position.y;
	a_star->start.g = 0;
	a_star->start.father = ft_initfather();
	a_star->openl->next = NULL;
	a_star->closel->next = NULL;
	a_star->map = map;
	a_star->wall = 1;
	ft_add_node(&a_star->openl, a_star->start);
	return (ft_a_star(a_star));
}
