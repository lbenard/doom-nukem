/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:02:27 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:05:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/preview_checkbox_entity.h"

void	preview_checkbox_entity_update(t_preview_checkbox_entity *const self)
{
	checkbox_entity_update(&self->super);
}
