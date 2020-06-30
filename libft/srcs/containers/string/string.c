/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:07:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:50:41 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/string.h"

t_constructor	string(const char *const str)
{
	static t_string_args	args;

	args.str = str;
	return (ft_constructor(init_string,
		destroy_string,
		sizeof(t_string),
		&args));
}
