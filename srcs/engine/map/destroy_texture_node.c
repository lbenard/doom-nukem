/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_texture_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:08:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:41:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"

void	destroy_texture_node(t_texture_node *const self)
{
	free((char*)self->key);
	destroy_image(&self->image);
}
