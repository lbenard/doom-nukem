/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:44:51 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:40:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"

t_constructor	texture_node(const char *key, const char *path)
{
	static t_texture_node_args	args;

	args.key = key;
	args.path = path;
	return (ft_constructor(init_texture_node,
		destroy_texture_node,
		sizeof(t_texture_node),
		&args));
}
