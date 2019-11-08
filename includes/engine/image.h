/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 07:17:53 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 16:29:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <SFML/Graphics.h>
# include "containers/module.h"
# include "sizes/usize.h"

typedef struct	s_image
{
	sfImage	*image;
	t_usize	size;
}				t_image;

typedef struct	s_image_args
{
	const char *path;
}				t_image_args;

t_constructor	image(const char *const path);

t_result		init_image(t_image *const self, const t_image_args *const args);
void			destroy_image(t_image *const self);

#endif
