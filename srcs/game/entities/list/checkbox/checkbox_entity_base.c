/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_entity_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:16:32 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/28 16:35:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"

t_constructor	checkbox_entity_base(const char *const base_name,
					const t_window *const window)
{
	static t_checkbox_entity_args	args;

	args.base_name = base_name;
	args.window = window;
	return (ft_constructor(init_checkbox_entity_base,
		destroy_checkbox_entity,
		sizeof(t_checkbox_entity),
		&args));
}
