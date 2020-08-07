/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 01:41:44 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/07 01:43:29 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/nyarlathotep_entity.h"

void	destroy_nyarlathotep_entity(t_nyarlathotep_entity *const self)
{
	destroy_module(&self->super.super.super.module);
}