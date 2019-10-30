/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:47:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 12:05:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELTA_H
# define DELTA_H

/*
** Time management.
** Delta time gives the time needed to render the last frame, so that any
** time-dependant update can scale to the speed of the game.
*/
void	set_last_delta(const float delta);
float	get_last_delta(void);
float	*get_delta_ptr(void);
double	get_wall_time(void);

#endif
