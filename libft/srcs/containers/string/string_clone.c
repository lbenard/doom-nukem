/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:09:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:50:39 by mribouch         ###   ########.fr       */
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
