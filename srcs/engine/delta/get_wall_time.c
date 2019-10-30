/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:48:11 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:51:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/time.h>
#include "engine/delta.h"

double	get_wall_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0.0);
	return ((double)time.tv_sec + (double)time.tv_usec * 0.000001);
}
