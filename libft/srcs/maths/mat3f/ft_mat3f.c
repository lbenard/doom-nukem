/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat3f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:12:56 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:56:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/mat3f.h"
#include "ft/mem.h"

t_mat3f	ft_mat3f(void)
{
	t_mat3f	retval;

	ft_bzero(&retval, sizeof(t_mat3f));
	return (retval);
}
