/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 05:08:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/26 20:24:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"

void	destroy_image(t_image *const self)
{
	sfImage_destroy(self->image);
	destroy_module(&self->module);
}
