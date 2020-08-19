/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attach_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 04:09:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 04:23:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

static void	player_movements(t_game *const self)
{
	input_attach(&self->input, self->inputs.forward,
		ft_key_event(sfKeyW, KEY_HOLD));
	input_attach(&self->input, self->inputs.forward,
		ft_key_event(sfKeyUp, KEY_HOLD));
	input_attach(&self->input, self->inputs.backward,
		ft_key_event(sfKeyS, KEY_HOLD));
	input_attach(&self->input, self->inputs.backward,
		ft_key_event(sfKeyDown, KEY_HOLD));
	input_attach(&self->input, self->inputs.left,
		ft_key_event(sfKeyA, KEY_HOLD));
	input_attach(&self->input, self->inputs.right,
		ft_key_event(sfKeyD, KEY_HOLD));
	input_attach(&self->input, self->inputs.jump,
		ft_key_event(sfKeySpace, KEY_HOLD));
	input_attach(&self->input, self->inputs.crouch,
		ft_key_event(sfKeyLControl, KEY_HOLD));
	input_attach(&self->input, self->inputs.sprint,
		ft_key_event(sfKeyLShift, KEY_HOLD));
	input_attach(&self->input, self->inputs.toggle_flight,
		ft_key_event(sfKeyF, 0));
}

static void	player_actions(t_game *const self)
{
	input_attach(&self->input, self->inputs.use,
		ft_key_event(sfKeyE, KEY_HOLD));
	input_attach(&self->input, self->inputs.pick,
		ft_key_event(sfKeyG, 0));
	input_attach(&self->input, self->inputs.shoot,
		ft_mouse_event(sfMouseLeft, MOUSE_HOLD));
	input_attach(&self->input, self->inputs.shoot,
		ft_key_event(sfKeyEnter, KEY_HOLD));
	input_attach(&self->input, self->inputs.reload,
		ft_key_event(sfKeyR, 0));
	input_attach(&self->input, self->inputs.camera_right,
		ft_key_event(sfKeyRight, KEY_HOLD));
	input_attach(&self->input, self->inputs.camera_left,
		ft_key_event(sfKeyLeft, KEY_HOLD));
	input_attach(&self->input, self->inputs.camera_up,
		ft_key_event(sfKeyPageUp, KEY_HOLD));
	input_attach(&self->input, self->inputs.camera_down,
		ft_key_event(sfKeyPageDown, KEY_HOLD | INVERT_INPUT));
}

static void	editor_inputs(t_game *const self)
{
	input_attach(&self->input, self->inputs.editor_camera_up,
		ft_key_event(sfKeyUp, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_up,
		ft_key_event(sfKeyW, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_right,
		ft_key_event(sfKeyRight, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_right,
		ft_key_event(sfKeyD, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_down,
		ft_key_event(sfKeyDown, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_down,
		ft_key_event(sfKeyS, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_left,
		ft_key_event(sfKeyLeft, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_left,
		ft_key_event(sfKeyA, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_dezoom,
		ft_key_event(sfKeySubtract, KEY_HOLD | INVERT_INPUT));
	input_attach(&self->input, self->inputs.editor_camera_dezoom,
		ft_key_event(sfKeyPageDown, KEY_HOLD | INVERT_INPUT));
	input_attach(&self->input, self->inputs.editor_camera_zoom,
		ft_key_event(sfKeyAdd, KEY_HOLD));
	input_attach(&self->input, self->inputs.editor_camera_zoom,
		ft_key_event(sfKeyPageUp, KEY_HOLD));
}

void		game_attach_inputs(t_game *const self)
{
	player_movements(self);
	player_actions(self);
	editor_inputs(self);
	input_attach(&self->input, self->inputs.quit, ft_key_event(sfKeyEscape, 0));
}
