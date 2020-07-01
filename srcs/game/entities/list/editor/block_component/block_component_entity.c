/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_component_entity.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:29:14 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 00:20:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_component_entity.h"

t_constructor	block_component_entity(const t_editor_block_descriptor *block)
{
	static t_block_component_entity_args	args;

	args.block = block;
	return (ft_constructor(init_block_component_entity,
		destroy_block_component_entity,
		sizeof(t_block_component_entity),
		&args));
}