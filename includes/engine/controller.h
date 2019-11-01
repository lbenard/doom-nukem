/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:28:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/01 22:30:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include <SFML/Window/Joystick.h>

/*
** -- XBOX 360 --
*/

/*
** Axis
*/
# define XBOX_LSTICK_X 0
# define XBOX_LSTICK_Y 1
# define XBOX_RSTICK_X 4
# define XBOX_RSTICK_Y 5
# define XBOX_DPAD_X 6
# define XBOX_DPAD_Y 7
# define XBOX_LTRIGGER 2
# define XBOX_RTRIGGER 3

int	xbox_perpendicular_axis(int axis);

/*
** Buttons
*/
# define XBOX_BACK sfJoystickPovX
# define XBOX_START sfJoystickPovY
# define XBOX_LBUMPER sfJoystickU
# define XBOX_RBUMPER sfJoystickV
# define XBOX_A sfJoystickX
# define XBOX_B sfJoystickY
# define XBOX_X sfJoystickZ
# define XBOX_Y sfJoystickR

#endif