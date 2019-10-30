/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat3f_identity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:18:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:57:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/mat3f.h"
#include "ft/mem.h"

t_mat3f	ft_mat3f_identity(void)
{
	t_mat3f	retval;

	ft_bzero(&retval, sizeof(t_mat3f));
	retval.m[0][0] = 1.0f;
	retval.m[1][1] = 1.0f;
	retval.m[2][2] = 1.0f;
	return (retval);
}
