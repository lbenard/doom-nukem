/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:09:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/07 17:44:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/string.h"

t_constructor	string_clone(const t_string_ref ref)
{
	static t_string_args	args;

	args.string_ref = ref;
	return (ft_constructor(init_string_clone,
		destroy_string,
		sizeof(t_string),
		&args));
}