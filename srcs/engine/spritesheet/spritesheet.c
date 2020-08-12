/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritesheet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:54:37 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/12 19:03:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/spritesheet.h"

t_constructor	spritesheet(const char *const path, const t_usize grid_size)
{
	static t_spritesheet_args	args;

	args.path = path;
	args.grid_size = grid_size;
	return (ft_constructor(init_spritesheet, destroy_spritesheet,
			sizeof(t_spritesheet), &args));
}