/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_descriptor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:26:40 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 17:26:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/block_descriptor.h"

t_constructor	block_descriptor(const char id,
					const char *name,
					const char *texture_path)
{
	static t_block_descriptor_args	args;

	args.id = id;
	args.name = name;
	args.texture_path = texture_path;
	return (ft_constructor(init_block_descriptor,
		destroy_block_descriptor,
		sizeof(t_block_descriptor),
		&args));
}
