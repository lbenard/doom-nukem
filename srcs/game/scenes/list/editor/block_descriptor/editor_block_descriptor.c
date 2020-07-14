/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_block_descriptor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:13:16 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/03 18:55:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_block_descriptor.h"

t_constructor	editor_block_descriptor(const char id,
					const char *name,
					const char *texture_path)
{
	static t_editor_block_descriptor_args	args;

	args.id = id;
	args.name = name;
	args.texture_path = texture_path;
	return (ft_constructor(init_editor_block_descriptor,
		destroy_editor_block_descriptor,
		sizeof(t_editor_block_descriptor),
		&args));
}
