/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:06:11 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:06:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/preview_checkbox_entity.h"

void	destroy_preview_checkbox_entity(t_preview_checkbox_entity *const self)
{
	destroy_checkbox_entity(&self->super);
}
