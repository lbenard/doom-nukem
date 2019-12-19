/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_entity_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:48:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/29 18:20:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/image_entity.h"

t_constructor	image_entity_from_file(const char *const path,
					const t_frame_transform transform)
{
	static t_image_entity_args	args;

	args.path = path;
	args.transform = transform;
	return (ft_constructor(init_image_entity_from_file,
		destroy_image_entity,
		sizeof(t_image_entity),
		&args));
}
