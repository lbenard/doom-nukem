/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 19:02:58 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/12 19:04:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/spritesheet.h"

void	destroy_spritesheet(t_spritesheet *const self)
{
	destroy_module(&self->module);
	free(self->sprite);
}
