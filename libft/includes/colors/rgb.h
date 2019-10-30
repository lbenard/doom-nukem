/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:15:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 17:06:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGB_H
# define RGB_H

# include "types.h"
# include "colors/hsv.h"

/*
** RGB color
*/
typedef struct	s_rgb
{
	t_u8	r;
	t_u8	g;
	t_u8	b;
}				t_rgb;

/*
** Constructors
*/
t_rgb			ft_rgb(t_u8 r, t_u8 g, t_u8 b);
t_rgb			ft_rgb_int(t_u32 color);
t_rgb			ft_rgb_hsv(t_hsv color);

/*
** Casts
*/
t_u32			rgb_to_int(t_rgb color);

#endif
