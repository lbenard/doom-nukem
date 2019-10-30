/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 00:49:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/27 00:50:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/string.h"

t_smodule_factory	string(const char *const str)
{
	static t_string_args	args;

	args.str = str;
	return (ft_smodule_factory(
		ft_smodule_descriptor(init_string, destroy_string),
		&args));
}