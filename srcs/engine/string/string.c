/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 00:49:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 05:16:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/string.h"

t_constructor	string(const char *const str)
{
	static t_string_args	args;

	args.str = str;
	return (ft_constructor(init_string,
		destroy_string,
		sizeof(t_string),
		&args));
}