/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:01:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 01:11:52 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/widepunchman_entity.h"

void	destroy_widepunchman_entity(t_widepunchman_entity *const self)
{
	destroy_module(&self->super.super.super.module);
}
