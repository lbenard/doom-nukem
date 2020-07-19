/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:01:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 19:01:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/onepunchman_entity.h"

void	destroy_onepunchman_entity(t_onepunchman_entity *const self)
{
	destroy_module(&self->super.super.super.module);
}
