/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_component_uid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:12:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:13:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/component.h"

t_component_uid	get_new_component_uid(void)
{
	static t_component_uid	uid_count = 0;

	return (uid_count++);
}