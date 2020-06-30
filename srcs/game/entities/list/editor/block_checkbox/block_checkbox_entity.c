/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_checkbox_entity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 00:31:34 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 00:33:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_checkbox_entity.h"

t_constructor	block_checkbox_entity(const char *const base_name,
					const char *const block_path,
					const t_window *const window)
{
	static t_block_checkbox_entity_args	args;

	args.base_name = base_name;
	args.block_path = block_path;
	args.window = window;
	return (ft_constructor(init_block_checkbox_entity,
		destroy_block_checkbox_entity,
		sizeof(t_block_checkbox_entity),
		&args));
}
