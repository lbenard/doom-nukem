/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_last_delta.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:09:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/04 23:12:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/delta.h"
#include "maths/maths.h"

void	set_last_delta(const float delta)
{
	*get_delta_ptr() = ft_fmin(delta, MAX_DELTA);
}
