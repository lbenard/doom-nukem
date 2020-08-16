/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:03:41 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/18 21:18:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_UTILS_H
# define RENDER_UTILS_H

# include "engine/frame.h"

void	render_row(t_frame *const frame,
			const t_usize start,
			const size_t length,
			const t_rgba color);
void	render_column(t_frame *const frame,
			const t_usize start,
			const size_t length,
			const t_rgba color);
void	render_line(t_frame *const frame,
			const t_isize start,
			const t_isize end,
			const t_rgba color);

#endif
