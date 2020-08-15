/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_component_entity.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:35:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/05 00:36:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/player_component_entity.h"

t_constructor	player_component_entity(const char *const icon_path)
{
	static t_player_component_entity_args	args;

	args.icon_path = icon_path;
	return (ft_constructor(init_player_component_entity,
		destroy_player_component_entity,
		sizeof(t_player_component_entity),
		&args));
}
