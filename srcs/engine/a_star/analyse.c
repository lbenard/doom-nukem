/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:54:13 by mribouch          #+#    #+#             */
/*   Updated: 2020/07/16 18:09:27 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/a_star.h"

int		ft_isvalid(const ssize_t x, const ssize_t y, const t_map *const map)
{
	return ((x >= 0 && x < (ssize_t)map->size.x) && (y >= 0 && y < (ssize_t)map->size.y));
}

int		ft_analyse(int x, int y, t_star *star)
{
	// if (star->map.map[y][x] >= star->wall ||
	if (star->map->map[y * star->map->size.x + x].id != ' '
		|| ft_find_node(&star->closel, x, y) == 1)
		return (1);
	if (ft_isvalid(x, y, star->map) == 0)
		return (1);
	return (0);
}

int		ft_validiag(int x, int y, t_star *star, t_node cur_node)
{
	if (x < cur_node.pos.x && y < cur_node.pos.y)
		if (ft_analyse(cur_node.pos.x, cur_node.pos.y - 1, star) == 0 ||
			ft_analyse(cur_node.pos.x - 1, cur_node.pos.y, star) == 0)
			return (0);
	if (x > cur_node.pos.x && y > cur_node.pos.y)
		if (ft_analyse(cur_node.pos.x, cur_node.pos.y + 1, star) == 0 ||
			ft_analyse(cur_node.pos.x + 1, cur_node.pos.y, star) == 0)
			return (0);
	if (x > cur_node.pos.x && y < cur_node.pos.y)
		if (ft_analyse(cur_node.pos.x, cur_node.pos.y - 1, star) == 0 ||
			ft_analyse(cur_node.pos.x + 1, cur_node.pos.y, star) == 0)
			return (0);
	if (x < cur_node.pos.x && y > cur_node.pos.y)
		if (ft_analyse(cur_node.pos.x, cur_node.pos.y + 1, star) == 0 ||
			ft_analyse(cur_node.pos.x - 1, cur_node.pos.y, star) == 0)
			return (0);
	return (1);
}

void	ft_check_start_end(t_node start, t_node end, const t_map *const map)
{
	if (ft_isvalid(start.pos.x, start.pos.y, map) == 0)
	{
		ft_putendl("Start point invalid !");
		exit(0);
	}
	if (ft_isvalid(end.pos.x, end.pos.y, map) == 0)
	{
		ft_putendl("Destination point is invalid !");
		exit(0);
	}
}

t_result	ft_is_openl_empty(t_star *star)
{
	t_star_list	*retop;
	t_star_list	*retclo;

	if (!(retop = malloc(sizeof(t_star_list))))
		return (ERROR);
	if (!(retclo = malloc(sizeof(t_star_list))))
		return (ERROR);
	retclo->next = NULL;
	retop->next = NULL;
	star->end = ft_closest_node(&star->closel, star->end);
	ft_delist(&star->closel);
	ft_delist(&star->openl);
	star->openl = retop;
	star->closel = retclo;
	ft_add_node(&star->openl, star->start);
	return (ft_a_star(star));
}