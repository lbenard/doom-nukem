/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:14:53 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 18:59:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/mat4f.h"
#include "ft/mem.h"

t_mat4f	ft_mat4f(void)
{
	t_mat4f	retval;

	ft_bzero(&retval, sizeof(t_mat4f));
	return (retval);
}
