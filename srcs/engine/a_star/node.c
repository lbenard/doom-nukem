/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:45:47 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/14 22:58:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/a_star.h"

t_node		*ft_get_node(t_star_list **list, int x, int y)
{
	t_star_list	*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		if (tmp->node.pos.x == x && tmp->node.pos.y == y)
			return (&tmp->node);
		tmp = tmp->next;
	}
	return (NULL);
}

t_father	ft_convertnode(t_node node)
{
	t_father father;

	father.pos.x = node.pos.x;
	father.pos.y = node.pos.y;
	father.g = node.g;
	father.f = node.f;
	return (father);
}

int			ft_count_node(t_star_list **list)
{
	t_star_list	*tmp;
	int			i;

	tmp = *list;
	i = 0;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int			ft_find_node(t_star_list **list, int x, int y)
{
	t_star_list	*tmp;

	tmp = *list;
	while (tmp->next != NULL)
	{
		if (tmp->node.pos.x == x && tmp->node.pos.y == y)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
