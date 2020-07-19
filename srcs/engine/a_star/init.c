/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:48:17 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 18:28:42 by mribouch         ###   ########.fr       */
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

t_result	init_astar(t_star *a_star,
				const t_map *const map,
				t_entity monstre,
				t_entity player)
{
	// if (!(star = malloc(sizeof(t_star))))
	// 	return (ERROR);
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
	ft_putendl("------------------");
	return (ft_a_star(a_star));
	// ft_delist(&openl);
}
