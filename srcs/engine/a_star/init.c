/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:48:17 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/15 23:34:57 by lbenard          ###   ########.fr       */
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

t_result	init(t_node *const self,
				const t_map *const map,
				t_mob monstre,
				t_mob player)
{
	t_star			*star;

	if (!(star = malloc(sizeof(t_star))))
		return (ERROR);
	if (!(star->closel = malloc(sizeof(t_star_list))))
		return (ERROR);
	if (!(star->openl = malloc(sizeof(t_star_list))))
		return (ERROR);
	star->start.pos.x = (int)monstre.pos.x;
	star->start.pos.y = (int)monstre.pos.y;
	star->end.pos.x = (int)player.pos.x;
	star->end.pos.y = (int)player.pos.y;
	star->start.g = 0;
	star->start.father = ft_initfather();
	star->openl->next = NULL;
	star->closel->next = NULL;
	star->map = map;
	star->wall = 1;
	ft_add_node(&star->openl, star->start);
	ft_putendl("------------------");
	return (ft_a_star(self, star));
	// ft_delist(&openl);
}
