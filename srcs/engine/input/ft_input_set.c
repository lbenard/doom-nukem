/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:34:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/28 17:01:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/input.h"

t_input_set	ft_input_set(const char *const key, const size_t id)
{
	t_input_set	ret;

	ret.key = key;
	ret.id = id;
	ret.value = 0.0f;
	return (ret);
}
