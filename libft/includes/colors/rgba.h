/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:15:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/07/21 15:38:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGBA_H
# define RGBA_H

# include "types.h"
# include "colors/hsv.h"
# include "colors/rgb.h"

/*
** RGBA color
*/
typedef union	u_rgba
{
	struct		s_colors
	{
		t_u8	r;
		t_u8	g;
		t_u8	b;
		t_u8	a;
	}			c;
	t_u32		integer;
}				t_rgba;

/*
** Constructors
*/
t_rgba			ft_rgba(t_u8 r, t_u8 g, t_u8 b, t_u8 a);
t_rgba			ft_rgba_rgb(t_rgb color);
t_rgba			ft_rgba_int(t_u32 color);
t_rgba			ft_rgba_hsv(t_hsv color);

#endif
