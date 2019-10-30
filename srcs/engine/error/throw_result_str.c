/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_result_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:24:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:51:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "types.h"

t_result	throw_result_str(const char *const fn, const char *const cause)
{
	throw_error_str(fn, cause);
	return (ERROR);
}
