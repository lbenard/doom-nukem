/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 03:57:19 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 04:23:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/game.h"

static void	register_player(t_game *const self)
{
	self->inputs.forward = input_register(&self->input, "Forward");
	self->inputs.backward = input_register(&self->input, "Backward");
	self->inputs.left = input_register(&self->input, "Left");
	self->inputs.right = input_register(&self->input, "Right");
	self->inputs.sprint = input_register(&self->input, "Sprint");
	self->inputs.jump = input_register(&self->input, "Jump");
	self->inputs.crouch = input_register(&self->input, "Crouch");
	self->inputs.toggle_flight = input_register(&self->input, "ToggleFlight");
	self->inputs.use = input_register(&self->input, "Use");
	self->inputs.pick = input_register(&self->input, "Pick");
	self->inputs.shoot = input_register(&self->input, "Shoot");
	self->inputs.reload = input_register(&self->input, "Reload");
	self->inputs.camera_right = input_register(&self->input, "CameraRight");
	self->inputs.camera_left = input_register(&self->input, "CameraLeft");
	self->inputs.camera_up = input_register(&self->input, "CameraUp");
	self->inputs.camera_down = input_register(&self->input, "CameraDown");
}

static void	register_editor(t_game *const self)
{
	self->inputs.editor_camera_up =
		input_register(&self->input, "EditorCameraUp");
	self->inputs.editor_camera_right =
		input_register(&self->input, "EditorCameraRight");
	self->inputs.editor_camera_down =
		input_register(&self->input, "EditorCameraDown");
	self->inputs.editor_camera_left =
		input_register(&self->input, "EditorCameraLeft");
	self->inputs.editor_camera_dezoom =
		input_register(&self->input, "EditorCameraDezoom");
	self->inputs.editor_camera_zoom =
		input_register(&self->input, "EditorCameraZoom");
}

void		game_register_inputs(t_game *const self)
{
	register_player(self);
	register_editor(self);
	self->inputs.quit = input_register(&self->input, "Quit");
}
