/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_colliding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:02:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:17:07 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/player_entity.h"
#include "maths/vec2i.h"

static t_bool	does_position_belong_to_range(t_vec2i pos,
					t_vec2i min,
					t_vec2i max)
{
	if (pos.x < min.x || pos.y < min.y || pos.x > max.x || pos.y > max.y)
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	does_position_belong_to_size(t_vec2i pos, t_usize size)
{
	t_vec2i	min;
	t_vec2i	max;

	min = ft_vec2i(0, 0);
	max = ft_vec2i(size.x - 1, size.y - 1);
	if (!does_position_belong_to_range(pos, min, max))
		return (FALSE);
	else
		return (TRUE);
}

static t_bool	is_block_empty(const t_map *const map, t_vec2i pos)
{
	if (!does_position_belong_to_size(pos, map->size))
		return (FALSE);
	else if (map->map[pos.x + pos.y * map->size.x].east_texture_ref)
		return (FALSE);
	else
		return (TRUE);
}

t_bool			is_colliding(const t_map *const map,
					const t_vec2f move,
					const float box_size,
					t_corners *const box_corner)
{
	if (!is_block_empty(map, ft_vec2i(move.x + box_size, move.y - box_size)))
		box_corner->ne = TRUE;
	if (!is_block_empty(map, ft_vec2i(move.x + box_size, move.y + box_size)))
		box_corner->se = TRUE;
	if (!is_block_empty(map, ft_vec2i(move.x - box_size, move.y + box_size)))
		box_corner->so = TRUE;
	if (!is_block_empty(map, ft_vec2i(move.x - box_size, move.y - box_size)))
		box_corner->no = TRUE;
	return (box_corner->ne || box_corner->se
		|| box_corner->so || box_corner->no);
}
