/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:47:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/04 23:27:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELTA_H
# define DELTA_H

# define MAX_DELTA 0.0333333333f

/*
** Time management.
** Delta time gives the time needed to render the last frame, so that any
** time-dependant update can scale to the speed of the game.
** The MAX_DELTA value defines the maximum value that the delta can hold. It
** helps preventing issues related to performances issues that could lead to
** unexpected big delta values and results
*/
void	set_last_delta(const float delta);
float	get_last_delta(void);
float	*get_delta_ptr(void);
double	get_wall_time(void);

#endif
