/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:39:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"

t_hmodule_factory	image_from_file(const char *const path)
{
	return (ft_hmodule_factory(ft_hmodule_descriptor(
		(t_new_fn)sfImage_createFromFile, sfImage_destroy), path));
}
