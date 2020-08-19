/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:52:17 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/19 01:30:29 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_GAME_H
# define HUD_GAME_H

# include "engine/animation.h"
# include "engine/spritesheet.h"

typedef	struct		s_hud_game
{
	t_module		module;
	t_spritesheet	heart_ss;
	t_animation		heart;
	t_animation		direction;
}					t_hud_game;

typedef struct		s_hud_game_args
{
	char			*heart_ss_path;
}					t_hud_game_args;

t_constructor		hud_game(char *heart_ss_path);

t_result			init_hud_game(t_hud_game *const self,
						t_hud_game_args *const args);

void				destroy_hud_game(t_hud_game *const self);

#endif
