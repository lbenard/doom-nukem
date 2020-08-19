/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:54:30 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/19 01:31:32 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "game/hud_game.h"

t_result		init_hud_game(t_hud_game *const self,
					t_hud_game_args *const args)
{
	init_module(&self->module);
	module_add(&self->module, &self->heart_ss, spritesheet(args->heart_ss_path,
		ft_usize(8, 1)));
	module_add(&self->module, &self->heart, animation(0, 9, 1));
	module_add(&self->module, &self->direction, animation(0, 8, 1));
	if (self->module.has_error)
	{
		destroy_hud_game(self);
		return (throw_result_str("init_hud_game()",
			"failed to init hud module"));
	}
	return (OK);
}

void			destroy_hud_game(t_hud_game *const self)
{
	destroy_module(&self->module);
}

t_constructor	hud_game(char *heart_ss_path)
{
	static t_hud_game_args	args;

	args.heart_ss_path = heart_ss_path;
	return (ft_constructor(init_hud_game, destroy_hud_game,
		sizeof(t_hud_game), &args));
}
