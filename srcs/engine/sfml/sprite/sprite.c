/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:00:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 05:13:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/sprite.h"

t_constructor	sprite(void)
{
	return (ft_constructor(init_sprite,
		destroy_sprite,
		sizeof(t_sprite),
		NULL));
}
