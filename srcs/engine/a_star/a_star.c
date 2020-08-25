/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:02:04 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/25 21:21:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "engine/a_star.h"

static t_node	ft_find_lower_f(t_star_list **list)
{
	t_node		ret;
	t_star_list	*tmp;

	ret.f = INT_MAX;
	tmp = *list;
	while (tmp->next != NULL)
	{
		if (tmp->node.f < ret.f)
			ret = tmp->node;
		tmp = tmp->next;
	}
	return (ret);
}

t_node			ft_closest_node(t_star_list **close, t_node end)
{
	t_star_list	*tmp;
	t_node		node;
	int			dist;
	int			lastdist;

	tmp = *close;
	lastdist = INT_MAX;
	while (tmp->next != NULL)
	{
		dist = (tmp->node.pos.x - end.pos.x) * (tmp->node.pos.x - end.pos.x) +
			(tmp->node.pos.y - end.pos.y) * (tmp->node.pos.y - end.pos.y);
		if (dist < lastdist)
		{
			lastdist = dist;
			node.pos.x = tmp->node.pos.x;
			node.pos.y = tmp->node.pos.y;
		}
		tmp = tmp->next;
	}
	return (node);
}

static t_result	ft_get_path(t_node cur_node, t_star *star)
{
	t_node	*find;
	t_node	*prev;
	int		i;

	i = 0;
	find = &cur_node;
	prev = find;
	while (find->pos.x != star->start.pos.x || find->pos.y != star->start.pos.y)
	{
		find = ft_get_node(&star->closel,
			find->father.pos.x, find->father.pos.y);
		if (find->pos.x != star->start.pos.x
			|| find->pos.y != star->start.pos.y)
			prev = find;
		i++;
	}
	star->next_pos.pos.x = prev->pos.x;
	star->next_pos.pos.y = prev->pos.y;
	ft_delist(&star->closel);
	ft_delist(&star->openl);
	return (OK);
}

t_result		ft_a_star(t_star *star)
{
	t_node	c_node;
	int		count;

	ft_check_start_end(star->start, star->end, star->map);
	while (star->openl)
	{
		c_node = ft_find_lower_f(&star->openl);
		if (c_node.pos.x == star->end.pos.x && c_node.pos.y == star->end.pos.y)
		{
			ft_add_node(&star->closel, c_node);
			break ;
		}
		if ((count = ft_count_node(&star->openl)) >= 1)
			ft_del_node(&star->openl, c_node.pos.x, c_node.pos.y);
		if (count <= 0)
			return (ft_is_openl_empty(star));
		ft_add_node(&star->closel, c_node);
		ft_check_child(star, c_node);
	}
	return (ft_get_path(c_node, star));
}
