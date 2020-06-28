/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:48:00 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/28 16:41:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/checkbox_entity.h"
#include "ft/str.h"

t_checkbox_entity	*create_checkbox(t_entity_list *const list,
						const char *const name,
						const t_window *const window)
{
	t_checkbox_entity	*ret;

	ret = (t_checkbox_entity*)entity_list_add_entity(list,
		checkbox_entity_base(name, window));
	return (ret);
}