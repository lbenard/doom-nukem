/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_entity_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 18:58:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/18 18:59:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/image_entity.h"

t_constructor	image_entity_size(const t_usize size)
{
	static t_image_entity_args	args;

	args.size = size;
	return (ft_constructor(
		init_image_entity_size,
		destroy_image_entity,
		sizeof(t_image_entity),
		&args));
}
