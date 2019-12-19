/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:31:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/04 15:32:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/string.h"

t_constructor	static_string(const char *const str)
{
	static t_static_string_args	args;

	args.str = str;
	return (ft_constructor(init_static_string,
		destroy_static_string,
		sizeof(t_static_string),
		&args));
}