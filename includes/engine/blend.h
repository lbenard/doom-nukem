/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:31:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/10 18:30:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLEND_H
# define BLEND_H

# include "colors/rgba.h"

/*
** Blend modes used with frames
*/
t_rgba	blend_add(const t_rgba back, const t_rgba front);
t_rgba	blend_colorize(const t_rgba back, const t_rgba front);
t_rgba	blend_invert(const t_rgba back, const t_rgba front);

#endif
