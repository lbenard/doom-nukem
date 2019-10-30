/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 00:31:57 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 12:04:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLEND_H
# define BLEND_H

# include "colors/rgba.h"

/*
** Blend modes used with frames
*/
t_u32	blend_add(const t_rgba *const back, const t_rgba *const front);

#endif
