/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:54:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 19:54:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/map.h"

t_constructor	block_node(const char *key, char **values)
{
	static t_block_node_args args;

	args.key = key;
	args.values = values;
	return (ft_constructor(init_block_node,
		destroy_block_node,
		sizeof(t_block_node),
		&args));
}