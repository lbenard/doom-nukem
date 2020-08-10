/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapon_specs_default.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 18:46:41 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/06 18:47:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/weapon_entity.h"

t_weapon_specs	ft_weapon_specs_default(void)
{
	t_weapon_specs	ret;

	ret.name = "";
	ret.clip = 0;
	ret.clip_size = 0;
	ret.damage = 0.0f;
	ret.shoot_time = 0.0f;
	ret.loading_time = 0.0f;
	ret.decay = 0.0f;
	return (ret);
}