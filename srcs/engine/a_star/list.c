/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:48:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/14 22:48:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/a_star.h"

void		ft_change_g(t_star_list **list, int g, t_father father, t_node find)
{
	t_star_list	*tmp;

	tmp = *list;
	while (tmp->next != NULL)
	{
		if (tmp->node.pos.x == find.pos.x && tmp->node.pos.y == find.pos.y)
		{
			tmp->node.g = g;
			tmp->node.father = father;
		}
		tmp = tmp->next;
	}
}

void		ft_delist(t_star_list **list)
{
	t_star_list	*tmp;

	if (*list != NULL)
	{
		while (*list)
		{
			tmp = (*list)->next;
			free(*list);
			*list = tmp;
		}
		*list = NULL;
	}
}

void		ft_del_node(t_star_list **list, int x, int y)
{
	t_star_list	*tmp;
	t_star_list	*previous;

	tmp = *list;
	previous = NULL;
	if ((tmp != NULL) && (tmp->node.pos.x == x && tmp->node.pos.y == y) && list)
	{
		*list = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp->node.pos.x != x || tmp->node.pos.y != y)
	{
		previous = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	if (previous)
		previous->next = tmp->next;
	free(tmp);
}

void		ft_add_node(t_star_list **list, t_node node)
{
	t_star_list	*new;

	if (!(new = malloc(sizeof(t_star_list))))
		return ;
	new->node = node;
	new->next = *list;
	*list = new;
}
