/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attach_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 04:09:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/11 10:00:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

static void	player_movements(t_game *const self)
{
	input_attach(&self->input, self->inputs.forward,
		ft_key_event(SDL_SCANCODE_W, KEY_HOLD));
	input_attach(&self->input, self->inputs.forward,
		ft_key_event(SDL_SCANCODE_UP, KEY_HOLD));
	input_attach(&self->input, self->inputs.backward,
		ft_key_event(SDL_SCANCODE_S, KEY_HOLD));
	input_attach(&self->input, self->inputs.backward,
		ft_key_event(SDL_SCANCODE_DOWN, KEY_HOLD));
	input_attach(&self->input, self->inputs.left,
		ft_key_event(SDL_SCANCODE_A, KEY_HOLD));
	input_attach(&self->input, self->inputs.right,
		ft_key_event(SDL_SCANCODE_D, KEY_HOLD));
	input_attach(&self->input, self->inputs.jump,
		ft_key_event(SDL_SCANCODE_SPACE, KEY_HOLD));
	input_attach(&self->input, self->inputs.crouch,
		ft_key_event(SDL_SCANCODE_LCTRL, KEY_HOLD));
	input_attach(&self->input, self->inputs.sprint,
		ft_key_event(SDL_SCANCODE_LSHIFT, KEY_HOLD));
	input_attach(&self->input, self->inputs.toggle_flight,
		ft_key_event(SDL_SCANCODE_F, 0));
}

static void	player_actions(t_game *const self)
{
	input_attach(&self->input, self->inputs.use,
		ft_key_event(SDL_SCANCODE_E, KEY_HOLD));
	input_attach(&self->input, self->inputs.pick,
		ft_key_event(SDL_SCANCODE_G, 0));
	input_attach(&self->input, self->inputs.shoot,
		ft_mouse_event(SDL_BUTTON_LMASK, MOUSE_HOLD));
	input_attach(&self->input, self->inputs.shoot,
		ft_key_event(SDL_SCANCODE_RETURN, KEY_HOLD));
	input_attach(&self->input, self->inputs.reload,
		ft_key_event(SDL_SCANCODE_R, 0));
	input_attach(&self->input, self->inputs.camera_right,
		ft_key_event(SDL_SCANCODE_RIGHT, KEY_HOLD));
	input_attach(&self->input, self->inputs.camera_left,
		ft_key_event(SDL_SCANCODE_LEFT, KEY_HOLD));
	input_attach(&self->input, self->inputs.camera_up,
		ft_key_event(SDL_SCANCODE_PAGEUP, KEY_HOLD));
	input_attach(&self->input, self->inputs.camera_down,
		ft_key_event(SDL_SCANCODE_PAGEDOWN, KEY_HOLD | INVERT_INPUT));
}

static void	editor_inputs(t_game *const self)
{
	input_attach(&self->input, self->inputs.editor_set_floor,
		ft_key_event(SDL_SCANCODE_1, 0));
	input_attach(&self->input, self->inputs.editor_set_ceiling,
		ft_key_event(SDL_SCANCODE_2, 0));
	input_attach(&self->input, self->inputs.editor_camera_up,
		ft_key_event(SDL_SCANCODE_W, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_right,
		ft_key_event(SDL_SCANCODE_D, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_down,
		ft_key_event(SDL_SCANCODE_S, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_left,
		ft_key_event(SDL_SCANCODE_A, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_dezoom,
		ft_key_event(SDL_SCANCODE_PAGEDOWN, KEY_HOLD | INVERT_INPUT));
	input_attach(&self->input, self->inputs.editor_camera_zoom,
		ft_key_event(SDL_SCANCODE_PAGEUP, KEY_HOLD));
}

void		game_attach_inputs(t_game *const self)
{
	player_movements(self);
	player_actions(self);
	editor_inputs(self);
	input_attach(&self->input, self->inputs.quit,
		ft_key_event(SDL_SCANCODE_ESCAPE, KEY_HOLD));
}
