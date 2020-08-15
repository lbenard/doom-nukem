/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:48:36 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 18:20:42 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/a_star.h"

t_node	ft_get_f(int x, int y, t_star *star, t_node cur_node)
{
	t_node	ret;

	ret.father = ft_convertnode(cur_node);
	if (x != cur_node.pos.x && y != cur_node.pos.y)
		ret.g = 14 + cur_node.g;
	else
		ret.g = 10 + cur_node.g;
	ret.h = (ft_ssabs(star->end.pos.x - x) + ft_ssabs(star->end.pos.y - y))
		* 10;
	ret.f = ret.g + ret.h;
	ret.pos.x = x;
	ret.pos.y = y;
	return (ret);
}

void	ft_check_child(t_star *star, t_node cur_node)
{
	t_node node;

	ft_diag(star, cur_node);
	if (ft_analyse(cur_node.pos.x - 1, cur_node.pos.y, star) == 0)
	{
		node = ft_get_f(cur_node.pos.x - 1, cur_node.pos.y, star, cur_node);
		ft_step_child(node, cur_node, star);
	}
	if (ft_analyse(cur_node.pos.x + 1, cur_node.pos.y, star) == 0)
	{
		node = ft_get_f(cur_node.pos.x + 1, cur_node.pos.y, star, cur_node);
		ft_step_child(node, cur_node, star);
	}
	if (ft_analyse(cur_node.pos.x, cur_node.pos.y - 1, star) == 0)
	{
		node = ft_get_f(cur_node.pos.x, cur_node.pos.y - 1, star, cur_node);
		ft_step_child(node, cur_node, star);
	}
	if (ft_analyse(cur_node.pos.x, cur_node.pos.y + 1, star) == 0)
	{
		node = ft_get_f(cur_node.pos.x, cur_node.pos.y + 1, star, cur_node);
		ft_step_child(node, cur_node, star);
	}
}

void	ft_step_child(t_node child, t_node cur_node, t_star *star)
{
	if (child.pos.x == star->end.pos.x && child.pos.y == star->end.pos.y)
	{
		child.father = ft_convertnode(cur_node);
		ft_add_node(&star->closel, child);
	}
	if (ft_find_node(&star->openl, child.pos.x, child.pos.y) == 1 &&
		ft_get_node(&star->openl, child.pos.x, child.pos.y)->f < child.f)
		return ;
	if (ft_find_node(&star->openl, child.pos.x, child.pos.y) == 1 &&
		child.g < ft_get_node(&star->openl, child.pos.x, child.pos.y)->g)
		ft_change_g(&star->openl, child.g, ft_convertnode(cur_node), child);
	else if (ft_find_node(&star->openl, child.pos.x, child.pos.y) == 0)
		ft_add_node(&star->openl, child);
}

void	ft_diag(t_star *star, t_node c_node)
{
	t_node	node;

	if (ft_analyse(c_node.pos.x - 1, c_node.pos.y - 1, star) == 0 &&
		ft_validiag(c_node.pos.x - 1, c_node.pos.y - 1, star, c_node) == 0)
	{
		node = ft_get_f(c_node.pos.x - 1, c_node.pos.y - 1, star, c_node);
		ft_step_child(node, c_node, star);
	}
	if (ft_analyse(c_node.pos.x + 1, c_node.pos.y - 1, star) == 0 &&
		ft_validiag(c_node.pos.x + 1, c_node.pos.y - 1, star, c_node) == 0)
	{
		node = ft_get_f(c_node.pos.x + 1, c_node.pos.y - 1, star, c_node);
		ft_step_child(node, c_node, star);
	}
	if (ft_analyse(c_node.pos.x - 1, c_node.pos.y + 1, star) == 0 &&
		ft_validiag(c_node.pos.x - 1, c_node.pos.y + 1, star, c_node) == 0)
	{
		node = ft_get_f(c_node.pos.x - 1, c_node.pos.y + 1, star, c_node);
		ft_step_child(node, c_node, star);
	}
	if (ft_analyse(c_node.pos.x + 1, c_node.pos.y + 1, star) == 0 &&
		ft_validiag(c_node.pos.x + 1, c_node.pos.y + 1, star, c_node) == 0)
	{
		node = ft_get_f(c_node.pos.x + 1, c_node.pos.y + 1, star, c_node);
		ft_step_child(node, c_node, star);
	}
}
