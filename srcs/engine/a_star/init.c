/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:48:17 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/14 23:58:27 by lbenard          ###   ########.fr       */
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

t_node			*init(const t_map *const map, t_mob monstre, t_mob player)
{
	t_star			*star;
	t_node			*node;

	if (!(star = malloc(sizeof(t_star))))
		return (NULL);
	if (!(star->closel = malloc(sizeof(t_star_list))))
		return (NULL);
	if (!(star->openl = malloc(sizeof(t_star_list))))
		return (NULL);
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
	node = ft_a_star(star);
	// ft_delist(&openl);
	return (node);
}
