/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_entity_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:48:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/image_entity.h"

t_hmodule_factory	image_entity_from_file(const char *const path)
{
	static t_image_entity_args	args;

	args.path = path;
	return (ft_hmodule_factory(ft_hmodule_descriptor(
		(t_new_fn)new_image_entity_from_file, free_image_entity), &args));
}
