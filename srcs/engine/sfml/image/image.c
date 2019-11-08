/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:39:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 05:05:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/image.h"

t_constructor	image(const char *const path)
{
	static t_image_args	args;

	args.path = path;
	return (ft_constructor(init_image, destroy_image, sizeof(t_image), &args));
}
