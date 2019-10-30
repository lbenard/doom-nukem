/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_entity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:17:47 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/button_entity.h"

t_hmodule_factory	button_entity(const char *const path,
							const t_window *const window)
{
	static t_button_entity_args	args;

	args.normal_texture_path = path;
	args.window = window;
	return (ft_hmodule_factory(ft_hmodule_descriptor(
		(void *(*)())new_button_entity, free_button_entity), &args));
}
